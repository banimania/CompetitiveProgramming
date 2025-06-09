#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> deg(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    deg[u]++, deg[v]++;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int leaf = 0;
  while (deg[leaf] != 1) leaf++;

  int yNode = adj[leaf][0];
  int root = -1;
  for (int rc : adj[yNode]) {
    if (deg[rc] != 1) {
      root = rc;
      break;
    }
  }

  cout << deg[root] << " " << deg[yNode] - 1 << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
