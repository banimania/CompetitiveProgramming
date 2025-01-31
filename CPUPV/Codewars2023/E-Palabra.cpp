#include <cctype>
#include <math.h>
#include <iostream>

int main() {
  std::string p;
  std::cin >> p;

  int mayus = 0;

  for (int i = 0; i < p.length(); i++) if (isupper(p[i])) mayus++;

  if (mayus > p.length() / 2) {
    for (int i = 0; i < p.length(); i++) std::cout << (char) toupper(p[i]);
    std::cout << std::endl;
  } else {
    for (int i = 0; i < p.length(); i++) std::cout << (char) tolower(p[i]);
    std::cout << std::endl;
  }

  return 0;
}
