#include <bits/stdc++.h>
using namespace std;

void solve() {
  int x, y;
  cin >> x >> y;

  int minScreensY = ceil(y / 2.0f);
  int spaceX = 15 * minScreensY - 4 * y;

  int minScreensX = 0;
  if (x > spaceX) {
    minScreensX = ceil((x - spaceX) / 15.0f);
  }

  cout << minScreensY + minScreensX << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
