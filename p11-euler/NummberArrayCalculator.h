#pragma once

#include <vector>

#include "string_helper_utils.h"







class NummberArrayCalculator
{
public:
	std::vector< unsigned int > convert_to_vector(const std::string numbers_as_string) const
	{
		
		bool is_number = helper::string_utils::is_number(numbers_as_string);
		unsigned int number = 0;
		std::vector<unsigned int> the_numbers;
		
		if (is_number)
		{
			number = helper::string_utils::str_to_number<unsigned int>(numbers_as_string);
			the_numbers.push_back(number);
		}


		return the_numbers;
	
	}



};