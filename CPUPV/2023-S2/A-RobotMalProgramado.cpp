#include <iostream>
#include <sstream>

int main() {
  std::string input;
  std::getline(std::cin, input);
  std::istringstream isstream(input);
  
  long long n = 0, s = 0;
  while (isstream >> n) {
    s += n;
    std::cout << s << " ";
  }
  std::cout << std::endl;

  return 0;
}
