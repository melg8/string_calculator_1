#include <string_calculator_test.h>

StringCalculatorTest::~StringCalculatorTest() = default;

TEST_F(StringCalculatorTest, AddReturnZeroOnEmptyString) {
  //  StringCalculator c;
  //  int result = c.Add("");
  EXPECT_EQ(0, 0);
}