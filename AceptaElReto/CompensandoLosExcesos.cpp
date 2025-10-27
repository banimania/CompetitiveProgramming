#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;

    ll lcm = (a * b) / __gcd(a, b);

    ll ans = lcm / a + lcm / b;
    ans--;

    cout << ans << "\n";
  }
  return 0;
}
