#pragma once

#include <vector>

#include "string_helper_utils.h"



class NummberArrayCalculator
{
public:
	std::vector< unsigned int > convert_to_vector(const std::string& numbers_as_string) const
	{
		std::vector<unsigned int> the_numbers;

		std::vector<std::string> numbers_List = get_string_List(numbers_as_string, " ");
		

		for (std::string number_str : numbers_List)
		{
			if (is_number(number_str))
			{
				the_numbers.push_back(get_number(number_str));
			}
			else
			{
				the_numbers.clear();
				break;
			}
		}


		return the_numbers;
	
	}

private:
	std::vector<std::string> get_string_List(const std::string& the_string_seperated, const std::string& deliminator) const
	{
		std::string the_string = the_string_seperated;

		std::vector<std::string> sList;

		helper::string_utils::explode(the_string, sList, deliminator);

		return sList;

	}




	unsigned int get_number(const std::string& s) const
	{
		return helper::string_utils::str_to_number<unsigned int>(s);
	}

	bool is_number(const std::string& s ) const
	{		   
		return helper::string_utils::is_number(s);
	}





};