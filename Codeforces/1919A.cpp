#include <iostream>

int main() {
  int t;
  std::cin >> t;

  while(t--) {
    int a, b;
    std::cin >> a >> b;
    std::cout << ((a + b) % 2 == 0 ? "Bob" : "Alice") << std::endl;
  }

  return 0;
}
