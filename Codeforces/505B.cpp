#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, vector<vector<int>>> adj;

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--, c--;

    if (!adj.count(c)) {
      adj[c] = vector<vector<int>>(n);
    }
    adj[c][a].push_back(b);
    adj[c][b].push_back(a);
  }

  int q;
  cin >> q;

  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    int cnt = 0;

    for (auto [c, l] : adj) {
      vector<bool> visited(n, false);
      visited[u] = true;

      stack<int> st;
      st.push(u);

      while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (current == v) {
          cnt++;
          break;
        }

        for (int neighbour : adj[c][current]) {
          if (!visited[neighbour]) {
            visited[neighbour] = true;
            st.push(neighbour);
          }
        }
      }
    }

    cout << cnt << endl;
  }

  return 0;
}
