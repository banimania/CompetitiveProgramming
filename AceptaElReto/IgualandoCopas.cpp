#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    ll ma = LLONG_MIN;
    ll suma = 0;
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;
      suma += x;
      ma = max(ma, x);
    }

    ll ans = ((ma * n) - suma);
    cout << ans << "\n";
  }
  return 0;
}
