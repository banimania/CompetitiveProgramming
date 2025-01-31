#include <cmath>
#include <iostream>

typedef long long int ll;

int main() {
  int tt;
  std::cin >> tt;
  std::string res[tt];

  for (int t = 0; t < tt; t++) {
    int a, b;
    std::cin >> a >> b;

    bool answer = false;
    if (a == 0 && b == 0) answer = true;
    else if (a % 2 == 0 && b == 0) answer = true;
    else if (a == 0 && b % 2 == 0) answer = true;
    else if (a % 2 == 0 && b % 2 == 0) answer = true;
    else if (a % 2 == 0 && a != 0) answer = true;
    res[t] = (answer ? "YES" : "NO");
  }

  for (int t = 0; t < tt; t++) {
    std::cout << res[t] << std::endl;
  }

  return 0;
}
