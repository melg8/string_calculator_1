#include <string>

#include <vector>

class StringCalculator {
 public:
  int Add(std::string numbers);

 private:
  static void ReplaceNewLines(std::string* numbers);

  void SplitNumbersBy(const std::string& numbers, char separator);

  int AddSplittedNumbers() const;

  std::vector<int> splitted_numbers_;
};
