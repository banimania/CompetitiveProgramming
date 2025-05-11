#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  bool ans = true;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x % 2) ans = false;
  }

  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
