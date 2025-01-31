#include <cstdlib>
#include <iostream>

int main() {
  int a;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cin >> a;
      if (a == 1) {
        std::cout << std::abs(i - 2) + std::abs(j - 2) << std::endl;
        return 0;
      }
    }
  }
  return 1;
}
