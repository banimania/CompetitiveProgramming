#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, pMax;
  while (cin >> n >> pMax) {
    if (!n && !pMax) break;

    ll ans = 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
      ll maxCurr = pMax - a[i];

      auto it = upper_bound(a.begin(), a.end(), maxCurr);
      if (it == a.end()) {
        ans += (n - i) - 1;
      } else {
        int index = it - a.begin() - 1;

        if (index <= i) continue;

        ans += (index - i);
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
