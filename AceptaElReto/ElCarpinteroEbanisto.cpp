#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int l, n;
  while (cin >> l >> n) {
    if (!l && !n) break;

    vector<int> cortes(n + 2, 0);
    for (int i = 1; i <= n; i++) {
      cin >> cortes[i];
    }
    cortes[n + 1] = l;

    vector<vector<int>> dp(n + 2, vector<int>(n + 2));

    for (int len = 2; len <= n + 1; len++) {
      for (int i = 0; i <= n + 1 - len; i++) {
        int j = len + i;
        dp[i][j] = INT_MAX;

        for (int k = i + 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + 2 * (cortes[j] - cortes[i]));
        }
      }
    }

    cout << dp[0][n + 1] << endl;
  }
  return 0;
}
