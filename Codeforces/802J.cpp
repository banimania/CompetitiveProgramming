#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 0

void solve() {
  int n;
  cin >> n;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;

    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  queue<pair<int, int>> q;
  vector<bool> visited(n, false);
  int ans = INT_MIN;
  q.push({0, 0});
  visited[0] = true;
  while (!q.empty()) {
    auto [curr, cost] = q.front();
    q.pop();
    
    ans = max(cost, ans);
    for (auto [neighbour, dist] : adj[curr]) {
      if (!visited[neighbour]) {
        q.push({neighbour, dist + cost});
        visited[neighbour] = true;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
