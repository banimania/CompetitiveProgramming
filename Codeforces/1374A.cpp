#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll x, y, n;
  cin >> x >> y >> n;

  ll mod = n % x;

  if (mod == y) {
    cout << n << endl;
    return;
  }

  if (mod > y) {
    cout << n - (mod - y) << endl;
    return;
  }

  cout << n - (n % x) - (x - y) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
