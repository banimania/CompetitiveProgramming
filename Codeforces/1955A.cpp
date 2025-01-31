#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define TESTCASES true

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  cout << (b < 2 * a ? ((n / 2) * b + (n % 2) * a) : a * n) << endl;
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
 
