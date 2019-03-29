#pragma once


#include <string>
#include <sstream>



namespace helper
{

	namespace string_utils
	{
		
		bool is_number(const std::string& s);

		template<typename T>
		T str_to_number(std::string s)
		{
			std::stringstream ss(s);
			T res;
			ss >> res;
			return res;

		}

	}
}