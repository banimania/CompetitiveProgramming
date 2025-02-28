#include <bits/stdc++.h>
using namespace std;

int manhattanDistance(const pair<int, int> &a, const pair<int, int> &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
  int n;
  cin >> n;

  vector<pair<int, int>> p(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] == INT_MAX) continue;
      int k = max(i, j) + 1;

      dp[i][k] = min(dp[i][k], dp[i][j] + manhattanDistance(p[j], p[k]));
      dp[k][j] = min(dp[k][j], dp[i][j] + manhattanDistance(p[i], p[k]));
    }
  }

  int ans = INT_MAX;

  for (int i = 0; i <= n; i++) {
    ans = min({ans, dp[i][n], dp[n][i]});
  }

  cout << ans << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
