#include <bits/stdc++.h>
using namespace std;

int dfs(int curr, vector<vector<pair<int, int>>> &adj, vector<int> &dp, vector<int> &next) {
  if (dp[curr] != -1) return dp[curr];
  int ans = 0;

  for (pair<int, int> neighbourWay : adj[curr]) {
    int neighbour = neighbourWay.first;
    int cost = neighbourWay.second;

    int dist = dfs(neighbour, adj, dp, next) + cost;
    if (dist > ans) {
      ans = dist;
      next[curr] = neighbour;
    }
  }

  return dp[curr] = ans;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;

    vector<vector<pair<int, int>>> adj(n);
    vector<int> inDeg(n);
    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      adj[u].push_back({v, c});
      inDeg[v]++;
    }

    vector<int> sources;
    for (int i = 0; i < n; i++) {
      if (!inDeg[i]) sources.push_back(i);
    }

    for (int i = 0; i < n; i++) {
      sort(adj[i].begin(), adj[i].end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        return a.first < b.first;
      });
    }

    vector<int> dp(n, -1), next(n, -1);
    int ans = INT_MIN, start = -1;

    sort(sources.begin(), sources.end());
    for (int i : sources) {
      int dist = dfs(i, adj, dp, next);
      if (dist > ans) {
        ans = dist;
        start = i;
      }
    }

    cout << ans << endl;

    vector<int> path;
    while (start != -1) {
      path.push_back(start);
      start = next[start];
    }

    for (int i = 0; i < path.size(); i++) {
      cout << path[i] + 1 << (i == path.size() - 1 ? "" : " ");
    }
    cout << endl;

  }
  return 0;
}
