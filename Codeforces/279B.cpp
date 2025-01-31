#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    int n, t;
    std::cin >> n >> t;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }

    int maxBooks = 0, currentSum = 0, start = 0;

    for (int end = 0; end < n; end++) {
      currentSum += a[end];

      while (currentSum > t) {
        currentSum -= a[start];
        start++;
      }

      maxBooks = std::max(maxBooks, end - start + 1);
    }

    std::cout << maxBooks << std::endl;
}

