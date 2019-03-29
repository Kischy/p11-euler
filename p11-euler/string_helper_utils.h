#pragma once


#include <string>
#include <sstream>

#include <exception>


namespace helper
{

	namespace string_utils
	{

		class NotANumberException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "The string is not a number exception.";
			}
		};

		
		bool is_number(const std::string& s);

		template<typename T>
		T str_to_number(std::string s)
		{
			if (!is_number(s)) throw NotANumberException();


			std::stringstream ss(s);
			T res;
			ss >> res;
			return res;

		}

	}
}