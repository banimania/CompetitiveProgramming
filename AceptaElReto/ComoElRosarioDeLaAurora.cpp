#include <bits/stdc++.h>
using namespace std;

void dfs(int pos, vector<bool> &visited, vector<vector<int>> &adj, int &f, int &s, bool flag) {
  if (flag) f++;
  else s++;

  visited[pos] = true;
  for (int neighbour : adj[pos]) {
    if (!visited[neighbour]) {
      dfs(neighbour, visited, adj, f, s, !flag);
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, p, a;
  while (cin >> n >> p >> a) {
    vector<bool> visited(n, false);
    vector<vector<int>> adj(n);
    for (int i = 0; i < p; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<pair<int, int>> groups;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        int f = 0;
        int s = 0;
        dfs(i, visited, adj, f, s, false);
        groups.push_back({f, s});
      }
    }

    vector<vector<int>> dp(groups.size() + 1, vector<int>(a + 1));
    int ans = -1;

    for (int i = 1; i <= groups.size(); i++) {
      for (int j = 0; j <= a; j++) {
        // no hacer nada
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);

        // el primero
        if (j >= groups[i - 1].first) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - groups[i - 1].first] + groups[i - 1].first);
        }

        // el segundo 
        if (j >= groups[i - 1].second) {
          dp[i][j] = max(dp[i][j], dp[i - 1][j - groups[i - 1].second] + groups[i - 1].second);
        }

        ans = max(ans, dp[i][j]);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
