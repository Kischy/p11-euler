#include "pch.h"


#include "../p11-euler/NummberArrayCalculator.h"

class NummberArrayCalculatorStringConverter : public testing::Test
{
public:
	NummberArrayCalculator num_arr_calc;
};


TEST(NummberArrayCalculatorExists, IsAClass) {
	NummberArrayCalculator numbercalc;
}


TEST_F(NummberArrayCalculatorStringConverter, ReturnsEmptyVectorOnEmptyString)
{
	std::vector<unsigned int> empty_vector;
	ASSERT_EQ(num_arr_calc.convert_to_vector(""), empty_vector);
}

TEST_F(NummberArrayCalculatorStringConverter, ReturnsVectorOfOneNumberOnOneNumberString)
{
	std::vector<unsigned int> one_number_vector{ 7 };
	ASSERT_EQ(num_arr_calc.convert_to_vector("7"), one_number_vector);
}


TEST_F(NummberArrayCalculatorStringConverter, ReturnsVectorOfFourNumbersWhenSeperatedbyWhitespace)
{
	std::vector<unsigned int> four_number_vector{ 7, 3, 44, 7 };
	ASSERT_EQ(num_arr_calc.convert_to_vector("7 3 44 7"), four_number_vector);
}



TEST_F(NummberArrayCalculatorStringConverter, ReturnsTwoDimensionalVectorOnNewline)
{
	std::vector<std::vector<unsigned int> > twoD_vector{ { 7, 3},{5,6,7},{89,2} };
	
	ASSERT_EQ(num_arr_calc.convert_to_vector("7 3\n5 6 7\n89 2").size(), 2);
}
