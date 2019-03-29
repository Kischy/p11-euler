

#include "string_helper_utils.h"


#include <cctype>


namespace
{
	bool is_plus_or_minus(const char letter){

		if (letter == '+' || letter == '-') return true;

		return false;

	}

	bool is_size_one(const std::string& s)
	{
		return s.size() == 1;
	}
}

namespace helper
{

	namespace string_utils
	{

		bool is_number(const std::string& s)
		{
			if (is_size_one(s) && is_plus_or_minus(s[0])) return false;

			unsigned int i = 0;
			if (s.size() > 0)
			{
				if (s[0] == '+' || s[0] == '-')
					i++;
			}
			else
			{
				return false;
			}

			int NoOfPoints = 0;

			for (; i < s.size(); i++)
			{
				if (std::ispunct(s[i]))
				{
					if (s[i] == '.')	NoOfPoints++;
					else				return false;
				}
				else if (!std::isdigit(s[i]))	return false;
			}

			if (NoOfPoints > 1)	return false;

			return true;
		}


	}
}