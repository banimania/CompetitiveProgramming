#include <iostream>

int main() {
  int t;
  std::cin >> t;
  bool r[t];
  for (int i = 0; i < t; i++) {
    int a, b, c;
    std::cin >> a >> b >> c;
    r[i] = (a + b == c);
  }

  for (int i = 0; i < t; i++) std::cout << (r[i] ? "+" : "-") << std::endl;

  return 0;
}
