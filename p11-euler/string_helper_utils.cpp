

#include "string_helper_utils.h"


#include <cctype>


using namespace std;


namespace
{
	bool is_plus_or_minus(const char letter){

		if (letter == '+' || letter == '-') return true;

		return false;

	}

	bool is_size_one(const string& s)
	{
		return s.size() == 1;
	}
}

namespace helper
{

	namespace string_utils
	{
		void explode(string str, vector<string>& list, const string& delim)
		{
			string str_left, str_right;

			size_t split = str.find(delim, 0);
			if (split == string::npos) list.push_back(str);

			while (split != string::npos)
			{

				split = str.find(delim, 0);
				str_left = str.substr(0, split);
				str_right = str.substr(split + delim.length(), string::npos);
				str = str_right;
				list.push_back(str_left);

				if (str_right.length() == 0) split = string::npos;

			}
		}


		bool is_number(const string& s)
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
				if (ispunct(s[i]))
				{
					if (s[i] == '.')	NoOfPoints++;
					else				return false;
				}
				else if (!isdigit(s[i]))	return false;
			}

			if (NoOfPoints > 1)	return false;

			return true;
		}


	}
}