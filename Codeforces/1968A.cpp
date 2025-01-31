#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define TESTCASES true

void solve() {
  ll x;
  cin >> x;
  
  ll max = LLONG_MIN, ans = LLONG_MIN;
  for (int y = 1; y < x; y++) {
    if (gcd(x, y) + y > max) {
      max = gcd(x, y) + y;
      ans = y;
    }
  }
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
 
