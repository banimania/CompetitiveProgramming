#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, c;
  while (cin >> p >> c) {
    vector<vector<int>> adj(p);

    for (int i = 0; i < c; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> visited(p);
    visited[0] = true;

    stack<int> st;
    st.push(0);

    while (!st.empty()) {
      int curr = st.top();
      st.pop();

      for (int neighbour : adj[curr]) {
        if (!visited[neighbour]) {
          visited[neighbour] = true;

          st.push(neighbour);
        }
      }
    }

    bool bici = true;

    for (int i = 0; i < p; i++) {
      if (!visited[i]) {
        bici = false;
        break;
      }
    }

    cout << (bici ? "BICI" : "A PIE") << endl;
  }
  return 0;
}
