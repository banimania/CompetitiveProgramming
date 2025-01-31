#include <iostream>

int main() {
  int n;
  std::cin >> n;

  std::string s;
  std::cin >> s;

  int res = 0;

  for (int i =1; i < s.length(); i++) {
    if (s[i - 1] == s[i]) res++;
  }

  std::cout << res << std::endl;


  return 0;
}
