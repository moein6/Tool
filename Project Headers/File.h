#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <string_view>

//	File control v 2.2

// Creating files in "fstream" mood.

enum class Mode
{
	Text,
	Binary
};

class File : public std::fstream
{
public:

	File(const std::string_view &filename, const Mode mode) {
		OpenFile(filename, mode);
	}
	
	File(const char* File_Name, const Mode mode) {
		OpenFile(std::string_view(File_Name), mode);
	}//	end 

	~File() {
		if (this->is_open())
			close();
	}//	end distructor



	//	Save string
	void Serialize(const std::string& str) {
		auto size = str.size();
		write(reinterpret_cast<char*>(&size), sizeof(size));
		write(str.data(), size);
	}


	template <typename ClassType>
	void m_write_at_Index(const ClassType &obj , const int &index) {
		seekp(sizeof(ClassType) * index);
		this << obj;
	}
	
	template <typename Ty>
	void m_write(const Ty& value) {
		this << value;
	}

	//	saving object in txt files.
	template<typename Ty>	friend File& operator << (File& file, const Ty& value) {
		if (!file.write(reinterpret_cast<char*>(&value), sizeof(Ty)))
			throw std::ios_base::failure("writing faild " + m_FilePath);
		return file;
	}
	


	//	=-----------------------------	 Read	--------------------------------------------------------------------------

	//	Read string
	void Deserialize(std::string& str) {
		size_t size = 0;
		std::string tempstr;

		read(reinterpret_cast<char*>(&size), sizeof(size));

		tempstr.resize(size);

		read(tempstr.data(), size);
		str = tempstr;
	}

	//	write at index
	template <typename Ty> 
	void m_read_at_index(Ty &obj , const int &index) {
		seekg(sizeof(Ty) * index);
		this >> obj;
	}

	template <typename Ty> 
	void m_read(Ty& obj) {
		this >> obj;
	}

	template<typename Ty>	friend File& operator >> (File& file, Ty& var) {
		if (!file.read(reinterpret_cast<char*>(&var), sizeof(Ty)))
			throw std::ios_base::failure("Reading failed " + m_FilePath);
		return file;
	}

private:
	void OpenFile(std::string_view filename, const Mode mode) {
		m_FilePath = std::string(filename);
		auto usermode = mode == Mode::Binary ? std::ios::binary : std::ios::app;
		

		auto Openmode = std::ios::in | std::ios::out | usermode;
			
		open(m_FilePath, Openmode);

		if (!is_open()) {
			// Try to create file
			
			auto create_mode = std::ios::out | usermode;

			std::ofstream creator(m_FilePath, create_mode);

			if (!creator.is_open()) {
				const auto err = std::string("Can not create file ") + m_FilePath;
				throw std::runtime_error(err);
			}
			
			creator.close();
			
			// Reopen
			open(m_FilePath, Openmode);
			return;
		}//	end if

	}//	end function

private:
	std::string m_FilePath;


};//	end class
