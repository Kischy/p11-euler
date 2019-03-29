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
	//ASSERT_THROW(str_to_number<int>("a"), NotANumberExpeption);
}







