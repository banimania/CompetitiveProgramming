#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

void solve() {
  int n, x, o = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) o |= (i % ((~x) & (x + 1)));
  for (int i = 0; i < n; i++) cout << (o == x ? (i % ((~x) & (x + 1))) : (i == 0 ? x : ((i - 1) % ((~x) & (x + 1))))) << (i == n - 1 ? "\n" : " ");
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
