#include <cctype>
#include <iostream>

int main() {
  std::string first, second;
  int sum = 0;
  
  std::cin >> first;
  std::cin >> second;

  for (int i = 0; i < first.length(); i++) {
    first[i] = tolower(first[i]);
    second[i] = tolower(second[i]);
  }

  int result = 0;
  if (first > second) result = 1;
  else if (first < second) result = -1;

  std::cout << result << std::endl;
  return 0;
}
