#include <iostream>
#include <vector>
#include <math.h>

int main() {
  int tt;
  std::cin >> tt;
  std::vector<std::string> res;
  while (tt--) {
    int r, cx, cy, px, py;
    std::cin >> r >> cx >> cy >> px >> py;
    res.push_back((r >= sqrt(pow(cx - px, 2) + pow(cy - py, 2))) ? "SI" : "NO");
  }

  for (int i = 0; i < res.size(); i++) std::cout << res[i] << std::endl;

	return 0;
}
