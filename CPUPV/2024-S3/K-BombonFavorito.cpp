#include <iostream>

int main() {
  int tt;
  std::cin >> tt;

  bool res[tt];

  for (int i = 0; i < tt; i++) {
    bool f = false;
    int n, c;
    std::cin >> n >> c;
    for (int j = 0; j < n; j++) {
      int b;
      std::cin >> b;
      if (f) continue;
      if (b == c) {
        f = true;
      }
    }
    res[i] = f;
  }

  for (int i = 0; i < tt; i++) {
    std::cout << (res[i] ? "YES" : "NO") << std::endl;
  }
  return 0;
}
