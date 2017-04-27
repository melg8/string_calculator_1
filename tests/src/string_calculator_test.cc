#include <string_calculator_test.h>

#include <string_calculator.h>

StringCalculatorTest::~StringCalculatorTest() = default;

TEST_F(StringCalculatorTest, AddReturnZeroOnEmptyString) {
  StringCalculator c;
  int result = c.Add("");
  EXPECT_EQ(0, result);
}

TEST_F(StringCalculatorTest, AddReturnValueOfSingleNumberString) {
  const std::string single_number = "5";

  StringCalculator c;
  int result = c.Add(single_number);
  EXPECT_EQ(5, result);
}
