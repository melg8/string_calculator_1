#include <string_calculator.h>

#include <algorithm>
#include <cassert>
#include <numeric>
#include <sstream>

int StringCalculator::Add(std::string numbers) {
  ReplaceNewLines(&numbers);
  SplitNumbersBy(numbers, ',');
  return AddSplittedNumbers();
}

void StringCalculator::ReplaceNewLines(std::string* numbers) {
  assert(numbers);
  std::replace(std::begin(*numbers), std::end(*numbers), '\n', ',');
}

void StringCalculator::SplitNumbersBy(const std::string& numbers,
                                      char separator) {
  std::istringstream ss(numbers);
  std::string number;
  splitted_numbers_.clear();
  while (std::getline(ss, number, separator)) {
    splitted_numbers_.push_back(std::stoi(number));
  }
}

int StringCalculator::AddSplittedNumbers() const {
  return std::accumulate(std::begin(splitted_numbers_),
                         std::end(splitted_numbers_), 0);
}
