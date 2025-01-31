#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int a, b;
  std::cin >> a >> b;
  int c;
  std::vector<int> uno, repes;
  for (int i = 0; i < a; i++) {
    std::cin >> c;
    uno.push_back(c);
  }
  for (int i = 0; i < b; i++) {
    std::cin >> c;
    if (std::find(repes.begin(), repes.end(), c) != repes.end()) continue;
    if (std::find(uno.begin(), uno.end(), c) != uno.end()) repes.push_back(c);
  }
  for (int i = 0; i < repes.size(); i++) std::cout << repes[i] << " ";
  std::cout << std::endl;

  return 0;
}
