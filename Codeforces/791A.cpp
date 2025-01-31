#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  int i = 0;
  while (a <= b) {
    a *= 3;
    b *= 2;
    i++;
  }
  std::cout <<i << std::endl;
  return 0;
}
