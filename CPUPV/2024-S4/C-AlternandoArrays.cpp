#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int a[n], b[n];

  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    a[i] = x;
  }

  for (int i = 0; i < n; i++) {
    int x;
    std::cin >> x;
    b[i] = x;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << ((i + j) % 2 == 0 ? a[j] : b[j]) << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
