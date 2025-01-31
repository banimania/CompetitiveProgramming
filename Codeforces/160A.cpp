#include <algorithm>
#include <iostream>

int minCoins(int* a, int n, int sum) {
  if (n == 1) return 1;

  int minCoinsTaken = n;
  for (int i = 0; i < n; i++) {
    int sumI = 0;
    for (int j = 0; j < i; j++) {
      sumI += a[j];
    }

    if (sumI > sum - sumI) minCoinsTaken = std::min(minCoinsTaken, i);
  }
  return minCoinsTaken;
}

int main() {
  int n;
  std::cin >> n;
  int a[n];
  int sol[n];
  int sum = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }

  std::sort(a, a + n, [](int a, int b) { return a > b; });

  std::cout << minCoins(a, n, sum) << std::endl;

  return 0;
}
