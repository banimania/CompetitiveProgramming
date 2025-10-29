#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, x, y, xPy, xMy;
  while (cin >> n && n) {
    int max1 = INT_MIN, min1 = INT_MAX;
    int max2 = INT_MIN, min2 = INT_MAX;

    for (int i = 0; i < n; i++) {
      cin >> x >> y;

      xPy = x + y;
      xMy = x - y;

      if (xPy > max1) max1 = xPy;
      if (xPy < min1) min1 = xPy;
      if (xMy > max2) max2 = xMy;
      if (xMy < min2) min2 = xMy;
    }

    cout << max(max1 - min1, max2 - min2) << "\n";
  }
  return 0;
}
