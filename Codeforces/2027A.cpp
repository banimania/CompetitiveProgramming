#include <iostream>

int main() {
  int tt;
  std::cin >> tt;
  int sol[tt];

  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;
    
    int maxW = 0;
    int maxH = 0;

    for (int i = 0; i < n; i++) {
      int w, h;
      std::cin >> w >> h;
      maxW = std::max(w, maxW);
      maxH = std::max(h, maxH);
    }

    sol[t] = (2 * maxW + 2 * maxH);
  }

  for (int t = 0; t < tt; t++) {
    std::cout << sol[t] << std::endl;
  }
}
