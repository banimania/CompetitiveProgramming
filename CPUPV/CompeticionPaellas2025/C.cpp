#include <bits/stdc++.h>
using namespace std;

bool dfs(int curr, vector<vector<pair<int, int>>> &adj, vector<int> &prev, vector<bool> &visited, int open) {
  if (curr == adj.size() - 1 && !open) {
    vector<int> path;

    while (curr != -1) {
      path.push_back(curr);
      curr = prev[curr];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << " ";
    for (int i = 0; i < path.size(); i++) {
      cout << path[i] + 1 << " ";
    }
    cout << endl;
    
    return true;
  }

  for (auto [neighbour, par] : adj[curr]) {
    if (par == ')' && !open) continue;

    visited[neighbour] = true;
    if (par == '(') {
      prev[neighbour] = curr;
      if (dfs(neighbour, adj, prev, visited, open + 1)) return true;
    } else {
      prev[neighbour] = curr;
      if (dfs(neighbour, adj, prev, visited, open - 1)) return true;
    }
    visited[neighbour] = false;
  }

  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    char c;

    cin >> u >> v >> c;
    u--, v--;

    adj[u].push_back({v, c});
  }

  vector<bool> visited(n);
  vector<int> prev(n, -1);
  if (!dfs(0, adj, prev, visited, 0)) {
    cout << -1 << endl;
  }

  return 0;
}
