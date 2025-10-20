#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t, n, x, ma, mi;
  cin >> t;
  while (t--) {
    cin >> n;

    ma = INT_MIN, mi = INT_MAX;
    for (int i = 0; i < n; i++) {
      cin >> x;
      ma = max(ma, x);
      mi = min(mi, x);
    }

    cout << ma - mi - n + 1 << "\n";
  }
  return 0;
}
