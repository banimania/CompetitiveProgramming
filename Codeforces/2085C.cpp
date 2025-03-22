#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll x, y;
  cin >> x >> y;

  if (x == y) {
    cout << -1 << endl;
    return;
  }

  if ((x & y) == 0) {
    cout << 0 << endl;
    return;
  }

  ll maxN = max(x, y);

  ll power = 0;
  while ((1 << power) <= maxN) {
    power++;
  }

  cout << (1 << power) - maxN << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
