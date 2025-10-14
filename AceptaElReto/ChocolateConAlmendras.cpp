#include <bits/stdc++.h>
using namespace std;

int sum(int i, int j, int i2, int j2, vector<vector<int>> &pSum) {
  return pSum[i2 + 1][j2 + 1] - pSum[i2 + 1][j] - pSum[i][j2 + 1] + pSum[i][j];
}

int minCuts(int i, int j, int i2, int j2, vector<vector<char>> &grid, vector<vector<vector<vector<int>>>> &dp, vector<vector<int>> &pSum) {
  int s = sum(i, j, i2, j2, pSum);

  if (s == 0 || s == (i2 - i + 1) * (j2 - j + 1)) return dp[i][j][i2][j2] = 0;
  if (dp[i][j][i2][j2] != INT_MAX) return dp[i][j][i2][j2];

  // cortes verticales
  for (int k = i; k < i2; k++) {
    dp[i][j][i2][j2] = min(dp[i][j][i2][j2], minCuts(i, j, k, j2, grid, dp, pSum) + minCuts(k + 1, j, i2, j2, grid, dp, pSum) + 1);
  }

  // cortes horizontales
  for (int k = j; k < j2; k++) {
    dp[i][j][i2][j2] = min(dp[i][j][i2][j2], minCuts(i, j, i2, k, grid, dp, pSum) + minCuts(i, k + 1, i2, j2, grid, dp, pSum) + 1);
  }

  return dp[i][j][i2][j2];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m;
  while (cin >> n >> m) {
    vector<vector<char>> grid(n, vector<char>(m));

    vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(m, INT_MAX))));
    vector<vector<int>> pSum(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];

        pSum[i + 1][j + 1] = (grid[i][j] == '#') + pSum[i][j + 1] + pSum[i + 1][j] - pSum[i][j];
      }
    }
    cout << minCuts(0, 0, n - 1, m - 1, grid, dp, pSum) << endl;
  }
  return 0;
}
