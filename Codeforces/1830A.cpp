#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  map<pair<int, int>, int> index;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);

    index[{u, v}] = i;
    index[{v, u}] = i;
  }

  vector<int> dp(n, 0), id(n, 0);
  dp[0] = 1;

  vector<bool> visited(n);
  visited[0] = true;

  stack<int> st;
  st.push(0);
  while (!st.empty()) {
    int curr = st.top();
    st.pop();

    for (int neighbour : adj[curr]) {
      if (!visited[neighbour]) {
        st.push(neighbour);
        visited[neighbour] = true;

        dp[neighbour] = dp[curr] + (index[{curr, neighbour}] < id[curr]);
        id[neighbour] = index[{curr, neighbour}];
      }
    }
  }

  int ans = 0;

  for (int i = 0; i < dp.size(); i++) {
    ans = max(dp[i], ans);
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
