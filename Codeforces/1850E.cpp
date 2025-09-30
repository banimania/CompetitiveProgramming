#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, c;
  cin >> n >> c;

  long double sum = 0;
  long double sumX = 0;
  long double sumX2 = 0;

  for (ll i = 0; i < n; i++) {
    ll s;
    cin >> s;

    sum += s * s;
    sumX += 2 * s;
    sumX2 += 1;
  }

  sum -= c;

  ll ans = (-sumX + sqrtl(sumX * sumX - 4 * sum * sumX2)) / (2 * sumX2);
  ans /= 2;

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
