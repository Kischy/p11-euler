#include "pch.h"


#include "../p11-euler/string_helper_utils.h"

using namespace helper::string_utils;


TEST(IsNumberFunction, ReturnsFalseOnEmptyString)
{
	ASSERT_FALSE(is_number(""));
}


TEST(IsNumberFunction, ReturnFalseOnLetter)
{
	ASSERT_FALSE(is_number("a"));
}


TEST(IsNumberFunction, ReturnTrueOnNumber)
{
	ASSERT_TRUE(is_number("-10"));
}

TEST(IsNumberFunction, ReturnFalseOnMinusOrPlus)
{
	ASSERT_FALSE(is_number("-"));
	ASSERT_FALSE(is_number("+"));
}

TEST(StringToNumberFunction, ReturnsPlus1)
{
	ASSERT_EQ(str_to_number<int>("+1"), 1);
}

TEST(StringToNumberFunction, ReturnsMinus1)
{
	ASSERT_EQ(str_to_number<int>("-1"), -1);
}

TEST(StringToNumberFunction, ThrowsExceptionIfNotANumber)
{
	ASSERT_THROW(str_to_number<int>("+"), NotANumberException);
	ASSERT_THROW(str_to_number<int>("23213+"), NotANumberException);
}


//Please refractor
TEST(ExplodeStringToVectorFunction, GivesVectorWithOneElementOnEmptyString)
{
	std::string arbitraryDeliminator = " ";

	std::vector<std::string> sList;
	explode("", sList, arbitraryDeliminator);

	ASSERT_EQ(1, sList.size());
}


//Please refractor
TEST(ExplodeStringToVectorFunction, GivesTwoStringsWhenSeperatedbyDeliminator)
{
	std::string arbitraryDeliminator = " ";

	std::vector<std::string> sList;
	explode("dsa 123,", sList, arbitraryDeliminator);


	ASSERT_EQ(2, sList.size());
	ASSERT_EQ("dsa", sList.at(0));
	ASSERT_EQ("123,", sList.at(1));
}




