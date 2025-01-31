#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int min, max;
  for (int i = 0; i < n; i++) {
    int p;
    std::cin >> p;

    if (i == 0) {
      min = p;
      max = p;
      continue;
    } else {
      if (p > max) max = p;
      else if (p < min) min = p;
    }
  }

  std::cout << min << " " << max << std::endl;

  return 0;
}
