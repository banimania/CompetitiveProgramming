#include <bits/stdc++.h>
using namespace std;

// TODO: arreglar

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
        if (dp[i][j] == INT_MAX) continue;
        int k = max(i, j) + 1;
        if (k > n) continue;
        dp[k][j] = min(dp[k][j], dp[i][j] + manhattanDist(buts[i], buts[k]));
        dp[i][k] = min(dp[i][k], dp[i][j] + manhattanDist(buts[j], buts[k]));
      }
    }

    int ans = INT_MAX;
    pair<int, int> salida = {f - 1, c - 1};
    for (int i = 0; i <= n; i++) {
      ans = min({
        ans,
        dp[i][n],
        dp[n][i]
        // (dp[i][n] != INT_MAX ? dp[i][n] + max(manhattanDist(buts[i], salida), manhattanDist(buts[n], salida)) : INT_MAX),
        // (dp[n][i] != INT_MAX ? dp[n][i] + max(manhattanDist(buts[i], salida), manhattanDist(buts[n], salida)) : INT_MAX)
      });
    }

    ans += 1;
    cout << ans << endl;
  }
  return 0;
}

