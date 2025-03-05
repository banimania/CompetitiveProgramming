#include <bits/stdc++.h>
using namespace std;

int maxMin(int i, int j, vector<vector<int>> &dp) {
  if (i == 1 && j == 1) return 0;
  if (i <= 0 || j <= 0) return 0;
  if (dp[i][j] != INT_MAX) return dp[i][j];

  return dp[i][j] = max(
    maxMin(i - 2, j + 1, dp) + 1,
    maxMin(i + 1, j - 2, dp) + 1
  );
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> dp(200, vector<int>(200, INT_MAX));

  cout << maxMin(n, m, dp) << endl;

  return 0;
}
