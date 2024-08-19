#pragma once
#include <iomanip>
#include <string_view>

#if __has_include(<iostream>) or __has_include(<source_location>)
#include <iostream>
#include <source_location>
#endif // __has_include(<iostream>)


class Screen
{

#define Pause  std::cin.get(),std::cin.get();
#define Clear std::system("cls")
#define Stop std::cin.get(); std::cin.get();


public:

	//	show Text
	template <typename Ty>	friend Screen& operator << (Screen& screen, const Ty text) {
		std::cout << text;
	return screen;
	}

	//	show Message
	template <typename Ty>	friend Screen& operator == (Screen& screen, const Ty text) {
		std::cout << "[MASSAGE] : " << text;
	return screen;
	}

	//	show Error
	template <typename Ty>	friend Screen& operator || (Screen& screen, const Ty text) {
		std::cerr << "[ERROR] : " << text << '\a';
	return screen;
	}

	//	Show code line and message
	auto Code_Error(const std::string_view Message, const std::source_location Code_Data = std::source_location::current()) {
		
		*this || Message;
		*this << "\nFile : " << Code_Data.file_name() << '\n';
		*this << "function :" << Code_Data.function_name() << '\n';
		*this << "Line : " << Code_Data.line() << '\n';
		
	}


};

