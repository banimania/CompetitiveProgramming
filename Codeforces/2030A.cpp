#include <algorithm>
#include <iostream>
#include <vector>

int score(int* b, int* c, int n) {
  int score = 0;
  for (int i = 0; i < n; i++) {
    score += (c[i] - b[i]);
  }
  return score;
}

int main() {
  int tt;
  std::cin >> tt;
  int sol[tt];


  for (int t = 0; t < tt; t++) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int mina[n];
    int maxa[n];

    int min = 0, max = 0;
    int minIndex = 0, maxIndex = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
      if (a[i] < min) {
        min = a[i];
        minIndex = i;
      }
      if (a[i] > max) {
        max = a[i];
        maxIndex = i;
      }
    }

    /*if (n >= 2) {
      a.erase(a.begin() + std::max(minIndex, maxIndex));
      a.erase(a.begin() + std::min(minIndex, maxIndex));
      a.insert(a.begin(), min);
      a.insert(a.begin(), max);
    }*/

    if (n >= 2) {
      std::iter_swap(a.begin(), std::max_element(a.begin(), a.end()));
      std::iter_swap(a.begin() + 1, std::min_element(a.begin(), a.end()));
    }

    /*for (int i = 0; i < n; i++) std::cout << a[i] << " ";
    std::cout << std::endl;*/

    for (int i = 0; i < n; i++) {
      if (i == 0) {
        mina[i] = a[i];
        maxa[i] = a[i];
      } else {
        mina[i] = std::min(mina[i-1], a[i]);
        maxa[i] = std::max(maxa[i - 1], a[i]);
      }
    }

    int b[n], c[n];
    for (int i = 0; i < n; i++) {
      b[i] = mina[i];
      c[i] = maxa[i];
    }

    sol[t] = score(b, c, n);
  }

  for (int t = 0; t < tt; t++) std::cout << sol[t] << std::endl;
  return 0;
}
