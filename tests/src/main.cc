#include <gtest/gtest.h>

#include <string_calculator.h>

int main(int argc, char** argv) {
  StringCalculator c;
  std::string a;
  c.Test();

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
