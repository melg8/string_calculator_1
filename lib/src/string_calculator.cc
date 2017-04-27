#include <string_calculator.h>

int StringCalculator::Add(const std::string& numbers) try {
  return std::stoi(numbers);
} catch (const std::exception&) {
  return 0;
}
