#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m, d;
    cin >> n >> m >> d;

    int ans = m * n - d * ((n - 1) * n) / 2;
    cout << ans << "\n";
  }
  return 0;
}
