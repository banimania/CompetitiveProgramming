#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<pair<int, int>>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, c;
    cin >> u >> v >> c;

    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }

  vector<int> dist(n, INT_MAX);
  dist[0] = true;
  stack<int> st;
  st.push(0);

  int u = 0;
  while (!st.empty()) {
    int curr = st.top();
    st.pop();

    if (dist[curr] > dist[u]) u = curr;

    for (auto [neighbour, cost] : adj[curr]) {
      int newDist = dist[curr] + cost;

      if (dist[neighbour] == INT_MAX) {
        dist[neighbour] = newDist;
        st.push(neighbour);
      }
    }
  }

  int v = u;
  dist = vector<int>(n, INT_MAX);
  dist[v] = 0;
  st.push(v);
  while (!st.empty()) {
    int curr = st.top();
    st.pop();

    if (dist[curr] > dist[v]) v = curr;

    for (auto [neighbour, cost] : adj[curr]) {
      int newDist = dist[curr] + cost;

      if (dist[neighbour] == INT_MAX) {
        dist[neighbour] = newDist;
        st.push(neighbour);
      }
    }
  }

  cout << dist[v] << endl;
  return 0;
}
