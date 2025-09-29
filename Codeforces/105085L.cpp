#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, e, x, t;
  while (cin >> n >> e >> x >> t) {
    if (!n && !e && !x && !t) break;

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++) {
      dp[i][i] = 0;
    }

    for (int i = 0; i < e; i++) {
      int u, v, c;
      cin >> u >> v >> c;

      u--, v--;

      dp[u][v] = min(dp[u][v], c);
      dp[v][u] = dp[u][v];
    }

    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
          }
        }
      }
    }

    vector<int> ans;

    for (int i = 0; i < x; i++) {
      vector<bool> works(n);
      int o;
      cin >> o;

      for (int j = 0; j < o; j++) {
        int city;
        cin >> city;

        for (int k = 0; k < n; k++) {
          if (dp[city - 1][k] < t) {
            works[k] = true;
          }
        }

      }

      bool good = true;
      for (int j = 0; j < n; j++) {
        if (!works[j]) {
          good = false;
          break;
        }
      }

      if (good) ans.push_back(i + 1);
    }

    if (ans.size()) {
      for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
      }
      cout << endl;
    } else {
      cout << "NO HAY EMPRESAS" << endl;
    }
  }
  return 0;
}
