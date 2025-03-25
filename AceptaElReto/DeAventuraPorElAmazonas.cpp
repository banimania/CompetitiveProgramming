#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        int x;
        cin >> x;
        dp[i][j] = min(dp[i][j], x);
      }
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX && dp[i][j] > dp[i][k] + dp[k][j]) {
            dp[i][j] = dp[i][k] + dp[k][j];
          }
        }
      }
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
        cout << dp[i][j] << (j == n - 1 ? "" : " ");
      }
      cout << endl;
    }
  }

  return 0;
}
