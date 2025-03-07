#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> r(n);
  for (int i = 0; i < n; i++) cin >> r[i];
  int m;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; i++) cin >> b[i];

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
  dp[0][0] = 0;

  int ans = INT_MIN;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i < n) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + r[i]);
      if (j < m) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + b[j]);

      ans = max(ans, dp[i][j]);
    }
  }
  
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
