#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int s[n];
  for (int i = 0; i < n; i++) {
    int h;
    std::cin >> h;
    s[i] = h;
  }

  for (int i = 0; i < n; i++) {
    int h;
    std::cin >> h;
    s[i] += h;
  }

  for (int i = 0; i < n; i++) {
    std::cout << s[i] << " ";
  }
  std::cout << std::endl;

  return 0;
}
