#include <cctype>
#include <iostream>

int main() {
  std::string input;
  std::cin >> input;
  input[0] = toupper(int(input[0]));
  std::cout << input << std::endl;
  return 0;
}
