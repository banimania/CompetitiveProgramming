#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll a, b, k;
  cin >> a >> b >> k;

  ll ans = (k / 2 + (k % 2)) * a + (k / 2) * (-b);

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
