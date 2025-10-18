#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int x;
    cin >> x;

    int ans = 0;

    for (int i = 0; i < 31; i++) {
      ans += (bool)((1 << i) & x);
    }

    cout << ans << "\n";
  }
}
