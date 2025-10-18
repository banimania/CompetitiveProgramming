#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ans = max(ans, x);

  }
  cout << ans << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
