#include <iostream>

void printArrow(int n, int w) {
  if (n == w * 2 - 1) return;

  std::string line = "";
  if (n < w) for (int i = 0; i < n + 1; i++) line += "#";
  else for (int i = 0; i < w * 2 - n - 1; i++) line += "#";

  std::cout << line << std::endl;
  printArrow(n + 1, w);
}

int main() {
	int w;
  std::cin >> w;

  printArrow(0, w);

  return 0;
}
