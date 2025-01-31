//https://codeforces.com/problemset/problem/231/A

#include <iostream>

int main() {
  int n, a, b, c;
  std::cin >> n;

  int sol = 0;
  while (n--) {
    std::cin >> a >> b >> c;
    if (a + b + c >= 2) {
      sol++;
    }
  }

  std::cout << sol << std::endl;

  return 0;
}
