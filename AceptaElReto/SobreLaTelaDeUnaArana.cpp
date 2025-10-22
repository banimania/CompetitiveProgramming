#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll p;
  while (cin >> p && p) {
    ll suma = 0;

    ll ans = 0;
    ll x;
    while (cin >> x) {
      if (!x) break;

      suma += x;

      if (suma <= p) {
        ans++;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
