#include <string_calculator.h>

#include <algorithm>
#include <cassert>
#include <numeric>
#include <sstream>

static const char kDefaultDelimeter = ',';

int StringCalculator::Add(std::string numbers) {
  Normalize(&numbers);
  SplitNumbersBy(numbers, kDefaultDelimeter);
  CheckForNegativeNumbers();
  return AddSplittedNumbers();
}

void StringCalculator::Normalize(std::string* numbers) {
  assert(numbers);
  ReplaceCustomDelimiters(numbers, kDefaultDelimeter);
  ReplaceDelimiters(numbers, '\n', kDefaultDelimeter);
}

void StringCalculator::ReplaceDelimiters(std::string* numbers,
                                         char old_delimiter,
                                         char new_delimiter) {
  assert(numbers);
  std::replace(std::begin(*numbers), std::end(*numbers), old_delimiter,
               new_delimiter);
}

void StringCalculator::ReplaceCustomDelimiters(std::string* numbers,
                                               char new_delimiter) {
  assert(numbers);
  if (ContainsCustomDelimiter(*numbers)) {
    const auto custom_delimiter = SeparateCustomDelimiter(numbers);
    ReplaceDelimiters(numbers, custom_delimiter, new_delimiter);
  }
}

char StringCalculator::SeparateCustomDelimiter(std::string* numbers) {
  assert(numbers);
  const auto delimiter = numbers->at(2);
  *numbers = numbers->substr(4, numbers->size());

  return delimiter;
}

bool StringCalculator::ContainsCustomDelimiter(const std::string& numbers) {
  if (numbers.size() < 3) {
    return false;
  }
  return numbers[0] == '/' && numbers[1] == '/';
}

void StringCalculator::SplitNumbersBy(const std::string& numbers,
                                      char delimiter) {
  std::istringstream ss(numbers);
  std::string number;
  splitted_numbers_.clear();
  while (std::getline(ss, number, delimiter)) {
    splitted_numbers_.push_back(std::stoi(number));
  }
}

void StringCalculator::CheckForNegativeNumbers() {
  if (std::any_of(std::begin(splitted_numbers_), std::end(splitted_numbers_),
                  [](const auto value) { return value < 0; })) {
    throw std::string();
  }
}

int StringCalculator::AddSplittedNumbers() const {
  return std::accumulate(std::begin(splitted_numbers_),
                         std::end(splitted_numbers_), 0);
}
