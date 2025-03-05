#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 1

void solve(int tt) {
  int a;
  cin >> a;

  cout << (1 << __builtin_popcount(a)) << endl;
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
