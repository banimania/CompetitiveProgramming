#include <bits/stdc++.h>
using namespace std;

void dfs1(int curr, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st) {
  for (int next : adj[curr]) {
    if (!visited[next]) {
      visited[next] = true;
      dfs1(next, visited, adj, st);
    }
  }

  st.push(curr);
}

void dfs2(int curr, vector<int> &scc, int sccId, vector<vector<int>> &adj) {
  for (int next : adj[curr]) {
    if (scc[next] == -1) {
      scc[next] = sccId;
      dfs2(next, scc, sccId, adj);
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;
  
  string h, v;
  cin >> h >> v;

  vector<vector<int>> adj(n * m), adjT(n * m);

  for (int i = 0; i < h.size(); i++) {
    if (h[i] == '>') {
      for (int j = 0; j < m - 1; j++) {
        adj[i * m + j].push_back(i * m + j + 1);
        adjT[i * m + j + 1].push_back(i * m + j);
      }
    } else {
      for (int j = m - 1; j > 0; j--) {
        adj[i * m + j].push_back(i * m + j - 1);
        adjT[i * m + j - 1].push_back(i * m + j);
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    if (v[i] == 'v') {
      for (int j = 0; j < n - 1; j++) {
        adj[i + j * m].push_back(i + (j + 1) * m);
        adjT[i + (j + 1) * m].push_back(i + j * m);
      }
    } else {
      for (int j = n - 1; j > 0; j--) {
        adj[i + j * m].push_back(i + (j - 1) * m);
        adjT[i + (j - 1) * m].push_back(i + j * m);
      }
    }
  }

  stack<int> st;
  vector<bool> visited(n * m, false);
  for (int i = 0; i < n * m; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs1(i, visited, adj, st);
    }
  }

  vector<int> scc(n * m, -1);
  int sccId = 0;
  while (!st.empty()) {
    int i = st.top();
    st.pop();
    if (scc[i] == -1) {
      scc[i] = sccId;

      dfs2(i, scc, sccId, adjT);

      sccId++;
    }
  }

  cout << (sccId == 1 ? "YES" : "NO") << endl;
}

int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
