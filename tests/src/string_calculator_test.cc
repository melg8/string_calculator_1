#include <string_calculator_test.h>

#include <string_calculator.h>

StringCalculatorTest::~StringCalculatorTest() = default;

TEST_F(StringCalculatorTest, AddReturnsZeroOnEmptyString) {
  StringCalculator c;
  int result = c.Add("");
  EXPECT_EQ(0, result);
}

TEST_F(StringCalculatorTest, AddReturnsValueOfSingleNumberString) {
  const std::string single_number = "5";

  StringCalculator c;
  int result = c.Add(single_number);
  EXPECT_EQ(5, result);
}

TEST_F(StringCalculatorTest, AddReturnsSumOfTwoNumbersString1) {
  const std::string two_numbers = "1,2";

  StringCalculator c;
  int result = c.Add(two_numbers);
  EXPECT_EQ(3, result);
}

TEST_F(StringCalculatorTest, AddReturnsSumOfTwoNumbersString2) {
  const std::string two_numbers = "3,2";

  StringCalculator c;
  int result = c.Add(two_numbers);
  EXPECT_EQ(5, result);
}
