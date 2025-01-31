#include <algorithm>
#include <iostream>

int minSum(int* a, int* prefixSum, int n, int k) {
  if (k == n) return 1;

  int minIndex = -1;
  int min = 2147483647;
  for (int i = 0; i < n - k + 1; i++) {
    int suma = prefixSum[i + k - 1] - (i == 0 ? 0 : prefixSum[i - 1]);
    min = std::min(suma, min);
    if (min == suma) minIndex = i + 1;
  }
  return minIndex;
}

int main() {
  int n, k;
  std::cin >> n >> k;

  int a[n], prefixSum[n];
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (i == 0) prefixSum[0] = a[0];
    else prefixSum[i] = a[i] + prefixSum[i - 1];
  }

  std::cout << minSum(a, prefixSum, n, k) << std::endl;

  return 0;
}
