#include <bits/stdc++.h>
using namespace std;

string solve(int i, int j, vector<vector<char>> &grid, vector<vector<string>> &dp) {
  if (i == grid.size() - 1 && j == grid.size() - 1) return string(1, grid[i][j]);

  if (dp[i][j] != "") return dp[i][j];

  if (i == grid.size() - 1) {
    dp[i][j] = string(1, grid[i][j]) + solve(i, j + 1, grid, dp);
  } else if (j == grid.size() - 1) {
    dp[i][j] = string(1, grid[i][j]) + solve(i + 1, j, grid, dp);
  } else {
    string opt1 = string(1, grid[i][j]) + solve(i + 1, j, grid, dp);
    string opt2 = string(1, grid[i][j]) + solve(i, j + 1, grid, dp);

    dp[i][j] = min(opt1, opt2);
  }

  return dp[i][j];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<char>> grid(n, vector<char>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  vector<vector<string>> dp(n, vector<string>(n));

  cout << solve(0, 0, grid, dp) << "\n";
  return 0;
}
