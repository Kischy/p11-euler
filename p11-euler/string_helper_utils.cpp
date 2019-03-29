

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
		void explode(std::string str, std::vector<std::string>& list, const std::string& delim)
		{
			std::string str_left, str_right;
			//	str = str.substr (0, str.length());	// Zeilenumbruch entfernen

			int split = str.find(delim, 0);
			if (split == -1)
				list.push_back(str);

			while (split >= 0)
			{

				split = str.find(delim, 0);
				str_left = str.substr(0, split);
				str_right = str.substr(split + delim.length(), str.length());
				str = str_right;
				list.push_back(str_left);

				if (str_right.length() == 0)
					split = -1;

			}
		}


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