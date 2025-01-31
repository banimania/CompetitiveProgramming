#include <iostream>

int main() {
  int tt;
  std::cin >> tt;
  std::string sol[tt];

  for (int t = 0; t < tt; t++) {
    int s;
    std::cin >> s;

    std::string solution = "";
    for (int i = 0; i < s; i++) {
      solution += "0";
    }
    solution[s / 2] = '1';

    sol[t] = solution;
  }

  for (int t = 0; t < tt; t++) std::cout << sol[t] << std::endl;

  return 0;
}
