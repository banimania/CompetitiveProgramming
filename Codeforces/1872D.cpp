#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll tri(ll n) {
  return n * (n + 1) / 2;
}

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;

  ll mcm = (x * y) / __gcd(x, y);

  ll cntX = n / x - (n / mcm), cntY = n / y - (n / mcm);

  ll ans = tri(n) - tri(n - cntX) - tri(cntY);

  cout << ans << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
