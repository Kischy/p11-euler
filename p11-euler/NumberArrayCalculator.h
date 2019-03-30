#pragma once

#include <vector>
#include <algorithm>

#include "string_helper_utils.h"



class NumberArrayCalculator
{
public:

	unsigned int highest_product(size_t count_of_values) const
	{
		if(!valid_count(count_of_values)) return 0;


		return get_max_product(count_of_values);
	}

	void set_matrix(const std::string& matrix_as_string)
	{
		matrix = convert_matrix_to_vector(matrix_as_string);
	}

	std::vector<std::vector<unsigned int >> get_matrix() const
	{
		return matrix;
	}


	std::vector<std::vector<unsigned int >> convert_matrix_to_vector(const std::string& matrix_as_string) const
	{
		std::vector<std::vector<unsigned int >> the_numbers;

		std::vector<std::string> rows_List = get_string_List(matrix_as_string, "\n");

		for (std::string row : rows_List)
		{
			the_numbers.push_back(convert_row_to_vector(row));
		}


		return the_numbers;
	}


	std::vector< unsigned int > convert_row_to_vector(const std::string& numbers_as_string) const
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

	std::vector<std::vector<unsigned int >> matrix{};



	unsigned int get_max_product(size_t count_of_values) const
	{
		unsigned int max_pr = 0, pr_tmp = 0;

		for (size_t row = 0; row < matrix.size(); ++row)
		{
			for (size_t column = 0; column < matrix.at(row).size(); ++column)
			{
				pr_tmp = get_max_product(count_of_values, row, column);
				max_pr = get_max(max_pr, pr_tmp);

			}
		}


		return max_pr;
	}


	unsigned int get_max_product(size_t count_of_values, size_t row, size_t column) const
	{
		unsigned int max = 0, max_tmp = 0;

		max = get_right_down_product(count_of_values, row, column);
		max_tmp = max;

		max_tmp = get_down_product(count_of_values, row, column);
		max = get_max(max, max_tmp);

		max_tmp = get_right_product(count_of_values, row, column);
		max = get_max(max, max_tmp);

		max_tmp = get_right_up_product(count_of_values, row, column);
		max = get_max(max, max_tmp);


		return max;
	}

	unsigned int get_max(unsigned int val1, unsigned int val2) const
	{
		if (val1 > val2) return val1;

		return val2;

	}

	unsigned int get_right_up_product(size_t count_of_values, size_t row, size_t column) const
	{
		unsigned int product = get_element(row, column);

		for (size_t i = 1; i < count_of_values; ++i)
		{
			product *= right_up_of(row - i + 1, column + i - 1);
		}

		return product;

	}


	unsigned int get_right_down_product(size_t count_of_values, size_t row, size_t column) const
	{
		unsigned int product = get_element(row, column);

		for (size_t i = 1; i < count_of_values; ++i)
		{
			product *= right_down_of(row + i -1, column + i-1);
		}

		return product;

	}

	unsigned int get_down_product(size_t count_of_values, size_t row, size_t column) const
	{
		unsigned int product = get_element(row, column);

		for (size_t i = 1; i < count_of_values; ++i)
		{
			product *= down_of(row + i -1, column);
		}

		return product;

	}

	unsigned int get_right_product(size_t count_of_values, size_t row, size_t column) const
	{
		unsigned int product = get_element(row,column);

		for (size_t i = 1; i < count_of_values; ++i)
		{
			product *= right_of(row,column+i-1);
		}

		return product;

	}




	bool valid_count(size_t count_of_values) const
	{
		if (count_of_values == 0 || count_of_values == std::string::npos) return false;


		return true;
	}


	unsigned int left_down_of(size_t row, size_t column) const
	{
		if (is_left_boarder(column)) return 0;

		return get_element(row + 1, column - 1);
	}

	unsigned int right_up_of(size_t row, size_t column) const
	{
		if (is_up_boarder(row)) return 0;

		return get_element(row - 1, column + 1);
	}


	unsigned int left_up_of(size_t row, size_t column) const
	{
		if (is_left_boarder(column)) return 0;
		if (is_up_boarder(row)) return 0;

		return get_element(row - 1, column - 1);
	}


	unsigned int right_down_of(size_t row, size_t column) const
	{
		return get_element(row + 1, column+1);
	}


	unsigned int down_of(size_t row, size_t column) const
	{
		return get_element(row + 1, column);
	}

	unsigned int up_of(size_t row, size_t column) const
	{
		if (is_up_boarder(row)) return 0;

		return get_element(row-1, column);
	}

	bool is_up_boarder(size_t row) const
	{
		if (row == 0) return true;

		return false;

	}


	unsigned int right_of(size_t row, size_t column) const
	{
		return get_element(row, column+1);
	}


	unsigned int left_of(size_t row, size_t column) const
	{
		if (is_left_boarder(column)) return 0;

		return get_element(row, column-1);

	}
	


	bool is_left_boarder(size_t column) const
	{
		if (column == 0) return true;

		return false;

	}

	bool element_exists(size_t row, size_t column) const
	{

		if (row >= matrix.size())
		{
			return false;
		}

		if (column >= matrix.at(row).size())
		{
			return false;
		}

		return true;


	}

	unsigned int get_element(size_t row, size_t column) const
	{
		if (!element_exists(row, column)) return 0;

		return matrix.at(row).at(column);
	}

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