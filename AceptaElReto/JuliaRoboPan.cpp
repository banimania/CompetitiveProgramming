#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<int> &adj, vector<int> &visited, int &ans) {
  visited[curr] = 1;

  if (visited[adj[curr]] == 0) {
    dfs(adj[curr], adj, visited, ans);
  } else if (visited[adj[curr]] == 1) {
    ans++;
  }

  visited[curr] = 2;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n) {
    vector<int> adj(n);
    for (int i = 0; i < n; i++) {
      cin >> adj[i];
      adj[i]--;
    }
    
    vector<int> visited(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i, adj, visited, ans);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}
