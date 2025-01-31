#include <iostream>

int main() {
  std::string numString;
  std::cin >> numString;

  int s = 0;
  
  for (int i = 0; i < 16; i++) {
    int n = numString[i] - 48;
    if (i % 2 == 0) n = ((n * 2) % 10) + ((n * 2) / 10);

    s += n;
  }

  std::cout << ((s % 10 == 0) ? "YES" : "NO") << std::endl;

  return 0;
}
