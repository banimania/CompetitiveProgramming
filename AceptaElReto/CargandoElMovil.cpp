#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  while (cin >> m >> n) {
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    dp[n - 1][m - 1] = 2;

    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (i == n - 1 && j == m - 1) continue;

        dp[i][j] = max(2, min(dp[i + 1][j], dp[i][j + 1]) - grid[i][j]);
      }
    }

    cout << dp[0][0] << endl;
  }
  return 0;
}
