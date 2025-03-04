#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 1

void solve(int tt) {
  ll n;
  cin >> n;

  ll ans = 0;
  while (n >= 5) {
    ll aux = n / 5;
    ans += aux;
    n = aux;
  }
  cout << ans << endl;
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
