#include <iostream>

int main() {
  int tt;
  std::cin >> tt;
  std::string sol[tt];

  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;

    int x = 0;

    bool sakurako = true;
    int i = 1;
    while (abs(x) <= n) {
      if (sakurako) {
        x += std::min(2 * i - 1, -2 * i + 1);
      } else {
        x += std::max(2 * i - 1, -2 * i + 1);
      };
      //std::cout << (sakurako ? "Sakurako" : "Kosuke") << " X=" << x << std::endl;
      sakurako = !sakurako;
      i++;
    }
    sol[t] = !sakurako ? "Sakurako" : "Kosuke";
  }

  for (int t = 0; t < tt; t++) std::cout << sol[t] << std::endl;

  return 0;
}
