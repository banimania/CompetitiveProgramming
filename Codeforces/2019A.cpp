#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int tt;
  std::cin >> tt;
  std::vector<int> sol;
  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    int maxScore = 0;
    for (int i = 0; i < 2; i++) {
      // 0 rojos pares
      // 1 rojos impares
      int score = 0;
      int maxRed = 0;
      for (int j = 0; j < n; j++) {
        if ((i == 0 && j % 2 == 0) || (i == 1 && j % 2 != 0)) {
          score++;
          maxRed = std::max(a[j], maxRed);
        }
      }
      score += maxRed;
      maxScore = std::max(score, maxScore);
    }
    sol.push_back(maxScore);
  }

  for (int i = 0; i < sol.size(); i++) std::cout << sol[i] << std::endl;

  return 0;
}
