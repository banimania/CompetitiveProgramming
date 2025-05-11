#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(a[i] - i, ans);
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
