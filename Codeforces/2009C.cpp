#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, k;
    cin >> x >> y >> k;

    int xSt = ceil(x / (double) k);
    int ySt = ceil(y / (double) k);
    cout << (xSt > ySt ? 2 * xSt - 1 : 2 * ySt) << endl;
  }
  return 0;
}
