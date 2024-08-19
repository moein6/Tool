#pragma once
#include <fstream>

//	How to use : 
//	1 - Create a temperory object of your class as "Object" in this function.
//	2 - File name.
//	Result : this will return the new ID number.

template <typename Object> unsigned int Generate_ID(Object object, const char* File_Name) {

	unsigned int New_ID{ 0 };

	std::fstream Myfile(File_Name, std::ios::in | std::ios::out | std::ios::binary);

	if (Myfile.is_open()) {

		while (Myfile.read((char*)&object, sizeof(Object)))
				New_ID = object.Get_ID();

		Myfile.close();
	}

	return New_ID + 1;

}