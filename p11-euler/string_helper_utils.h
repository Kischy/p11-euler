#pragma once


#include <string>
#include <sstream>

#include <exception>
#include <vector>


namespace helper
{

	namespace string_utils
	{


		void explode(std::string str, std::vector<std::string>& list, const std::string& delim);
		bool is_number(const std::string& s);



		class NotANumberException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "The string is not a number exception.";
			}
		};


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