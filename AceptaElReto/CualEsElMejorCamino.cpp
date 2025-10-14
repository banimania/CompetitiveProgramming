#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, dist, calles;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n, c;
  while (cin >> n >> c) {
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < c; i++) {
      int u, v, l;
      cin >> u >> v >> l;
      u--, v--;

      adj[u].push_back({v, l});
      adj[v].push_back({u, l});
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
      int a, b;
      cin >> a >> b;
      a--, b--;

      int minCalles = 0;
      queue<State> q;
      vector<bool> visited(n);
      q.push({a, 0, 0});
      while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.pos == b) {
          minCalles = curr.calles;
          break;
        }

        for (const pair<int, int> &p : adj[curr.pos]) {
          if (!visited[p.first]) {
            visited[p.first] = true;
            q.push({p.first, curr.dist + p.second, curr.calles + 1});
          }
        }
      }

      priority_queue<State, vector<State>, function<bool(const State&, const State&)>> pq([](const State &a, const State &b) {
        if (a.dist == b.dist) return a.calles > b.calles;
        return a.dist > b.dist;
      });

      vector<int> best(n, INT_MAX);
      best[a] = 0;
      pq.push({a, 0, 0});
      int minCallesD = INT_MAX;
      while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        if (best[b] == curr.dist && curr.pos == b) {
          minCallesD = min(minCallesD, curr.calles);
        }

        for (const pair<int, int> &p : adj[curr.pos]) {
          if (best[p.first] >= curr.dist + p.second) {
            best[p.first] = curr.dist + p.second;
            pq.push({p.first, curr.dist + p.second, curr.calles + 1});
          }
        }
      }

      if (best[b] == INT_MAX) {
        cout << "SIN CAMINO" << endl;
      } else {
        cout << best[b] << " " << (minCallesD == minCalles ? "SI" : "NO") << endl;
      }
    }

    cout << "----" << endl;
  }
  return 0;
}
