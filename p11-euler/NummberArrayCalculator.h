#pragma once

#include <vector>
#include <string>

#include <fstream>


bool is_number(const std::string& s)
{
	uint i = 0;
	if (s.size() > 0)
	{
		if (s[0] == '+' || s[0] == '-')
			i++;
	}
	else
		return false;

	int NoOfPoints = 0;

	for (; i < s.size(); i++)
	{
		if (std::ispunct(s[i]))
		{
			if (s[i] == '.')
				NoOfPoints++;
			else
				return false;
		}
		else if (!std::isdigit(s[i]))
			return false;
	}

	if (NoOfPoints > 1)
		return false;

	return true;
}



template<typename T>
T str_to_number(std::string s)
{
	std::stringstream ss(s);
	T res;
	ss >> res;
	return res;

}




class NummberArrayCalculator
{
public:
	std::vector< unsigned int > convert_to_vector(const std::string numbers_as_string) const
	{
		bool is_number = is_number(numbers_as_string);
		unsigned int number = 0;
		
		if (is_number)
		{
			number = str_to_number<unsigned int>(numbers_as_string);
		}

		std::vector<unsigned int> the_numbers{number};

		return the_numbers;
	}


};