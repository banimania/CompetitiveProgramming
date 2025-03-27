#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll digitalRoot(ll x) {
  if (x < 10) return x;

  ll sum = 0;
  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }
  return digitalRoot(sum);
}

void solve() {
  ll k, x;
  cin >> k >> x;

  ll n = x + 1;
  while (digitalRoot(n) != x) n++;

  ll dif = n - x;

  ll ans = x + dif * (k - 1);

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
