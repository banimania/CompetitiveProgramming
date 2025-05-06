#include <bits/stdc++.h>
using namespace std;

int dfs(int curr, int parent, vector<vector<int>> &adj, vector<int> &cnt) {
  int ans = 1;

  for (int neighbour : adj[curr]) {
    if (neighbour != parent) ans += dfs(neighbour, curr, adj, cnt);
  }

  return cnt[curr] = ans;
}

int save(int curr, int parent, vector<vector<int>> &adj, vector<int> &cnt) {
  int ans = 0;

  vector<int> childs;
  for (int neighbour : adj[curr]) {
    if (neighbour != parent) childs.push_back(neighbour);
  }

  if (childs.size() == 1) ans = cnt[childs[0]] - 1;
  else if (childs.size() == 2) {
    ans = max(cnt[childs[0]] - 1 + save(childs[1], curr, adj, cnt), cnt[childs[1]] - 1 + save(childs[0], curr, adj, cnt));
  }

  return ans;
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> cnt(n);

  dfs(0, -1, adj, cnt);

  cout << save(0, -1, adj, cnt) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
