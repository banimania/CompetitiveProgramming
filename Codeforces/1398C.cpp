#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n;
  string str;
  cin >> n >> str;
  map<ll, ll> d = {{0, 1}};
  ll ans = 0, s = 0;

  for (ll i = 0; i < n; i++) {
    s += str[i] - '0';
    ll x = s - i - 1;
    if (!d.count(x)) d[x] = 0;
    d[x] += 1;
    ans += d[x] - 1;
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
