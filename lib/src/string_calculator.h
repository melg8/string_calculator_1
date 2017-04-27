#include <string>

#include <vector>

class StringCalculator {
 public:
  int Add(std::string numbers);

 private:
  static void Normalize(std::string* numbers);
  static void ReplaceCustomDelimiters(std::string* numbers, char new_delimiter);
  static char SeparateCustomDelimiter(std::string* numbers);
  static bool ContainsCustomDelimiter(const std::string& numbers);

  static void ReplaceDelimiters(std::string* numbers,
                                char old_delimiter,
                                char new_delimiter);

  void SplitNumbersBy(const std::string& numbers, char delimiter);

  int AddSplittedNumbers() const;

  std::vector<int> splitted_numbers_;
};
