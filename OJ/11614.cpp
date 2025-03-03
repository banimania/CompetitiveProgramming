#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    ll n;
    cin >> n;

    ll ans = (-1 + sqrt(1 + 8 * n)) / 2;
    cout << ans << endl;
  }
  return 0;
}
