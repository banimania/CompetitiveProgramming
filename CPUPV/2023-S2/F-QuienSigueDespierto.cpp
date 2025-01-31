#include <iostream>

int main() {
  int p, v;
  std::cin >> p >> v;
  
  int d = 0;

  for (int i = 0; i < p; i++) {
    int vec[v];
    for (int j = 0; j < v; j++) vec[j] = 0;
    for (int j = 0; j < 2 * v; j++) {
      char c;
      std::cin >> c;
      if (!vec[j / 2]) vec[j / 2] = (c == '#' ? 1 : 0);
    }
    for (int j = 0; j < v; j++) if (vec[j]) d++;
  }

  std::cout << d << std::endl;

  return 0;
}
