#include <iostream>
#include <sstream>

int main() {
  std::string in;
  std::getline(std::cin, in);
  std::istringstream iss(in);

  std::string res = "";
  bool f = true;
  int a, b;
  while (iss >> a) {
    if (f) {
      b = a;
      f = false;
      continue;
    }
    if (a == b) res += "I";
    else if (a > b) res += "S";
    else if (b > a) res += "B";
    b = a;
  }
  std::cout << res << std::endl;
  return 0;
}
