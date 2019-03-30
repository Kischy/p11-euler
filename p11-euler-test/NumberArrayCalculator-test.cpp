#include "pch.h"


#include "../p11-euler/NumberArrayCalculator.h"

class NumberArrayCalculatorStringConverter : public testing::Test
{
public:
	NumberArrayCalculator num_arr_calc;
};


class NumberArrayCalculatorTestTheCalculations : public testing::Test
{
public:
	NumberArrayCalculator num_arr_calc;

	const std::vector<std::vector<unsigned int> > resulting_matrix = { {1,36,68,87}, {04,100,16,73}, {20,69,100,41} };
	const unsigned int highest_val = 100;
	const unsigned int highest_product_2_call = 10000;
	const unsigned int highest_product_3_call = 282900;

	const std::string a_matrix =
		"1 36 68 87\n"
		"04 100 16 73\n"
		"20 69 100 41\n";

	virtual void SetUp()
	{
		num_arr_calc.set_matrix(a_matrix);
	}

};



TEST(NummberArrayCalculatorExists, IsAClass) {
	NumberArrayCalculator numbercalc;
}


TEST_F(NumberArrayCalculatorStringConverter, ReturnsEmptyVectorOnEmptyString)
{
	std::vector<unsigned int> empty_vector;
	ASSERT_EQ(num_arr_calc.convert_row_to_vector(""), empty_vector);
}

TEST_F(NumberArrayCalculatorStringConverter, ReturnsVectorOfOneNumberOnOneNumberString)
{
	std::vector<unsigned int> one_number_vector{ 7 };
	ASSERT_EQ(num_arr_calc.convert_row_to_vector("7"), one_number_vector);
}


TEST_F(NumberArrayCalculatorStringConverter, ReturnsVectorOfFourNumbersWhenSeperatedbyWhitespace)
{
	std::vector<unsigned int> four_number_vector{ 7, 3, 44, 7 };
	ASSERT_EQ(num_arr_calc.convert_row_to_vector("7 3 44 7"), four_number_vector);
}



TEST_F(NumberArrayCalculatorStringConverter, ReturnsTwoDimensionalVectorOnNewline)
{
	std::vector<std::vector<unsigned int> > twoD_vector{ { 7, 3},{5,6,7},{89,2} };

	std::vector<unsigned int> first_row = twoD_vector.at(0);
	std::vector<unsigned int> second_row = twoD_vector.at(1);
	std::vector<unsigned int> third_row = twoD_vector.at(2);

	std::vector<std::vector<unsigned int> > result = num_arr_calc.convert_matrix_to_vector("7 3\n5 6 7\n89 2");


	ASSERT_EQ(result.size(), 3);

	ASSERT_EQ(result.at(0), first_row);
	ASSERT_EQ(result.at(1), second_row);
	ASSERT_EQ(result.at(2), third_row);

	ASSERT_EQ(result.at(1).at(2), 7);

}


TEST_F(NumberArrayCalculatorTestTheCalculations, SetupCorrectly)
{
	std::vector<std::vector<unsigned int> > result = num_arr_calc.get_matrix();

	std::vector<unsigned int> first_row = resulting_matrix.at(0);
	std::vector<unsigned int> second_row = resulting_matrix.at(1);
	std::vector<unsigned int> third_row = resulting_matrix.at(2);


	ASSERT_EQ(result.at(0), first_row);
	ASSERT_EQ(result.at(1), second_row);
	ASSERT_EQ(result.at(2), third_row);

}

TEST_F(NumberArrayCalculatorTestTheCalculations, ReturnsZeroOnZeroCall)
{
	ASSERT_EQ(num_arr_calc.highest_product(0), 0);
}

TEST_F(NumberArrayCalculatorTestTheCalculations, ReturnsZeroOnNPosCall)
{
	ASSERT_EQ(num_arr_calc.highest_product(std::string::npos), 0);
}


TEST_F(NumberArrayCalculatorTestTheCalculations, ReturnsHighestNumberOn1Call)
{
	ASSERT_EQ(num_arr_calc.highest_product(1), highest_val);
}


TEST_F(NumberArrayCalculatorTestTheCalculations, ReturnsHighestProductOn2Call)
{
	ASSERT_EQ(num_arr_calc.highest_product(2), highest_product_2_call);
}


TEST_F(NumberArrayCalculatorTestTheCalculations, ReturnsHighestProductOn3Call)
{
	ASSERT_EQ(num_arr_calc.highest_product(3), highest_product_3_call);
}
