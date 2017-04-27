#include <string_calculator.h>

int StringCalculator::Add(const std::string& numbers) try {
  if (numbers.size() > 2) {
    return std::stoi(std::string{numbers.at(0)}) +
           std::stoi(std::string{numbers.at(2)});
  }
  return std::stoi(numbers);
} catch (const std::exception&) {
  return 0;
}
