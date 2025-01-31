//https://codeforces.com/problemset/problem/158/A

#include <iostream>

int main() {
  int n, k;
  std::cin >> n >> k;

  int sol = 0;

  int scores[n];
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    scores[i] = a;
  }

  int min = scores[k - 1];

  for (int i = 0; i < n; i++) {
    if (scores[i] >= min && scores[i] != 0) sol++;
  }

  std::cout << sol << std::endl;

  return 0;
}
