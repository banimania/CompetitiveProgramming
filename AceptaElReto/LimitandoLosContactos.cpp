#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &topo) {
  for (int neighbour : adj[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      dfs(neighbour, adj, visited, topo);
    }
  }

  topo.push(curr);
}

int dfs2(int curr, vector<vector<int>> &adj, vector<bool> &visited) {
  int ans = 1;
  for (int neighbour : adj[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      ans += dfs2(neighbour, adj, visited);
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n) {
    vector<vector<int>> adj(n), adjT(n);

    int nodo;
    while (cin >> nodo && nodo) {
      nodo--;
      int nCarr;
      cin >> nCarr;

      int x;
      while (nCarr--) {
        cin >> x;
        x--;

        adj[nodo].push_back(x);
        adjT[x].push_back(nodo);
      }
    }

    stack<int> topo;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        visited[i] = true;
        dfs(i, adj, visited, topo);
      }
    }

    fill(visited.begin(), visited.end(), false);

    int ans = 0;
    while (!topo.empty()) {
      int i = topo.top();
      topo.pop();
      if (!visited[i]) {
        visited[i] = true;

        ans = max(ans, dfs2(i, adjT, visited));
      }
    }
    
    cout << ans << endl;
  }
  return 0;
}
