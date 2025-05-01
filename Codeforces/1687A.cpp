#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  vector<ll> p(n);
  p[0] = a[0];
  for (ll i = 1; i < n; i++) p[i] = p[i - 1] + a[i];

  ll ans = 0;
  if (k <= n) {
    for (ll i = 0; i < n; i++) {
      ans = max(ans, p[i] - (i - k >= 0 ? p[i - k] : 0LL));
    }

    ans += k * (k - 1) / 2;
  } else {
    ans = p[n - 1] + n * (2 * k - n - 1) / 2;
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;

  while (t--) solve();

  return 0;
}
