#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, cost;
};

int main() {
  int n;
  while (cin >> n) {
    vector<int> loadTime(n);

    for (int i = 0; i < n; i++) {
      cin >> loadTime[i];
    }

    int m;
    cin >> m;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      adj[u].push_back({v, c});
    }

    vector<int> minT(n, INT_MAX);
    minT[0] = loadTime[0];

    priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
      return a.cost > b.cost;
    });

    pq.push({0, loadTime[0]});
    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      if (curr.pos == n - 1) break;
      if (curr.cost > minT[curr.pos]) continue;

      for (pair<int, int> enlace : adj[curr.pos]) {
        if (curr.cost + enlace.second + loadTime[enlace.first] < minT[enlace.first]) {
          minT[enlace.first] = curr.cost + enlace.second + loadTime[enlace.first];
          pq.push({enlace.first, curr.cost + enlace.second + loadTime[enlace.first]});
        }
      }
    }

    cout << (minT[n - 1] == INT_MAX ? "IMPOSIBLE" : to_string(minT[n - 1])) << endl;
  }
  return 0;
}
