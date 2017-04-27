#include <string>

#include <vector>

class StringCalculator {
 public:
  int Add(const std::string& numbers);

 private:
  void SplitNumbersBy(const std::string& numbers, char separator);

  int AddSplittedNumbers() const;

  std::vector<int> splitted_numbers_;
};
