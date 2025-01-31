#include <iostream>

int main() {
  int qq;
  std::cin >> qq;
  int seconds[qq];

  for (int q = 0; q < qq; q++) {
    std::string s, t;
    std::cin >> s >> t;

    int common = 0;
    for (int i = 0; i < std::min(s.length(), t.length()); i++) {
      if (s[i] == t[i]) common++;
      else break;
    }
    int sec = common;

    sec += (s.length() - common) + (t.length() - common);
    if (common > 0) sec++;

    seconds[q] = sec;
  }

  for (int q = 0; q < qq; q++) std::cout << seconds[q] << std::endl;
  return 0;
}
