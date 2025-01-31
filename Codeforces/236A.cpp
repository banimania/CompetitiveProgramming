#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::string input;
  std::cin >> input;

  std::vector<char> chars;
  for (int i = 0; i < input.length(); i++) {
    if (std::find(chars.begin(), chars.end(), input[i]) == chars.end()) {
      chars.push_back(input[i]);
    }
  }

  if (chars.size() % 2 == 0) std::cout << "CHAT WITH HER!" << std::endl;
  else std::cout << "IGNORE HIM!" << std::endl;

  return 0;
}
