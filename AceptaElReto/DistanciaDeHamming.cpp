#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;

    ll ans = 0;
    ll x = a ^ b;

    for (int i = 0; i < 63; i++) {
      if ((1ULL << i) & x) ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}
