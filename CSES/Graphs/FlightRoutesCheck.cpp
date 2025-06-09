#include <bits/stdc++.h>
using namespace std;

void dfs1(int curr, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &topo) {
  for (int neighbour : adj[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      dfs1(neighbour, adj, visited, topo);
    }
  }

  topo.push(curr);
}

void dfs2(int curr, vector<vector<int>> &adj, vector<int> &scc) {
  for (int neighbour : adj[curr]) {
    if (scc[neighbour] == -1) {
      scc[neighbour] = scc[curr];
      dfs2(neighbour, adj, scc);
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n), adjT(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    adj[a].push_back(b);
    adjT[b].push_back(a);
  }

  stack<int> topo;
  vector<bool> visited(n);

  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;

      dfs1(i, adj, visited, topo);
    }
  }

  int first = topo.top();

  vector<int> scc(n, -1);
  int cnt = 0;
  while (!topo.empty()) {
    int curr = topo.top();
    topo.pop();
    if (scc[curr] == -1) {
      scc[curr] = cnt++;
      dfs2(curr, adjT, scc);
    }
  }

  if (cnt == 1) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
    visited = vector<bool>(n);
    for (int i = 0; i < n; i++) {
      if (scc[i] != scc[first]) {
        cout << i + 1 << " " << first + 1 << endl;
        return 0;
      }
    }
  }
  
  return 0;
}
