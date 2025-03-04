#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  string s;
  cin >> s;

  if (s[0] == '0') {
    cout << 0 << endl;
    return;
  }

  bool leading = false;
  ll n = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      n++;
      if (i == 0) leading = true;
    }
  }

  ll ans = pow(10, n);
  if (leading) ans -= pow(10, n - 1);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve();
  }
  return 0;
}
