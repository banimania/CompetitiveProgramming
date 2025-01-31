//https://codeforces.com/problemset/problem/282/A

#include <iostream>

int main() {

  int n;
  std::cin >> n;

  int x = 0;

  while (n--) {
    std::string sentence;
    std::cin >> sentence;

    if (sentence.find("++") != std::string::npos) x++;
    if (sentence.find("--") != std::string::npos) x--;
  }

  std::cout << x << std::endl;

  return 0;
}
