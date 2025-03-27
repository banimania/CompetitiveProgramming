#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n, m;
  cin >> n >> m;

  ll ans = 0;
  for (ll i = 1; i * i <= m; i++) {
    if (m % i == 0 && m / i <= n) {
      if (m / i != i) ans += 2;
      else ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
