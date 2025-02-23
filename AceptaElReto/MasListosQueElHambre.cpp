#include <bits/stdc++.h>
using namespace std;

// TODO: arreglar con movimiento simúltaneo de ambos ratones

int manhattanDist(const pair<int, int> &a, const pair<int, int> &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  int f, c;
  while (cin >> f >> c) {
    int n;
    cin >> n;

    vector<pair<int, int>> buts(n + 1);
    buts[0] = {0, 0};
    for (int i = 1; i <= n; i++) {
      cin >> buts[i].first >> buts[i].second;
      buts[i].first--, buts[i].second--;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        if (i == j) continue;

        for (int k = i - 1; k >= 0; k--) {
          if (max(k, j) + 1 < i) break;
          if (dp[k][j] != INT_MAX) dp[i][j] = min(dp[i][j], dp[k][j] + manhattanDist(buts[k], buts[i]));
        }

        for (int k = j - 1; k >= 0; k--) {
          if (max(i, k) + 1 < j) break;
          if (dp[i][k] != INT_MAX) dp[i][j] = min(dp[i][j], dp[i][k] + manhattanDist(buts[k], buts[j]));
        }
      }
    }

    // for (int i = 0; i <= n; i++) {
    //   for (int j = 0; j <= n; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    int ans = INT_MAX;
    pair<int, int> salida = {f - 1, c - 1};
    for (int i = 0; i <= n; i++) {
      ans = min({
        ans,
        (dp[i][n] != INT_MAX ? dp[i][n] + max(manhattanDist(buts[i], salida), manhattanDist(buts[n], salida)) : INT_MAX),
        (dp[n][i] != INT_MAX ? dp[n][i] + max(manhattanDist(buts[i], salida), manhattanDist(buts[n], salida)) : INT_MAX)
      });
    }

    ans++;
    cout << ans << endl;
  }
  return 0;
}
