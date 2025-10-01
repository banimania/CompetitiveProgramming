#include <bits/stdc++.h>
using namespace std;

struct State {
  int h;
  int t;
  int b;
};

struct Edge {
  int u;
  int v;
  int c;
};

int main() {
  int n;
  while (cin >> n && n) {
    set<int> s;
    vector<Edge> edges(n);
    for (int i = 0; i < n; i++) {
      int u, v, c;
      cin >> u >> v >> c;

      s.insert(u);
      s.insert(v);

      edges[i] = {u, v, c};
    }

    int o, d, m;
    cin >> o >> d >> m;

    s.insert(o);
    s.insert(d);

    vector<int> heights(s.begin(), s.end());
    s.clear();

    unordered_map<int, int> x;
    for (int i = 0; i < heights.size(); i++) {
      x[heights[i]] = i;
    }

    vector<vector<pair<int, int>>> adj(heights.size());
    for (const Edge &edge : edges) {
      adj[x[edge.u]].push_back({x[edge.v], edge.c});
    }

    edges.clear();

    vector<vector<int>> best(heights.size(), vector<int>(m + 1, INT_MIN));

    best[x[o]][0] = 0;

    priority_queue<State, vector<State>, function<bool(const State &, const State&)>> pq([](const State &a, const State &b) {
      if (a.b == b.b) return a.t > b.t;
      return a.b < b.b;
    });

    pq.push({x[o], 0, 0});
    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();
      // cout << "H = " << curr.h << " B = " << curr.b << " T = " << curr.t << endl;

      if (best[curr.h][curr.t] != curr.b) continue;
      if (curr.t == m) continue;

      // bajar
      for (int nh = 0; nh < curr.h; nh++) {
        int dif = heights[curr.h] - heights[nh];
        int nt = curr.t + dif;
        if (nt <= m && best[nh][nt] < curr.b + dif) {
          best[nh][nt] = curr.b + dif;
          pq.push({nh, nt, curr.b + dif});
        }
      }

      for (const pair<int, int> &v : adj[curr.h]) {
        int nt = curr.t + v.second;
        int nh = v.first;
        int nb = curr.b;

        if (nt <= m) {
          if (best[nh][nt] < nb) {
            best[nh][nt] = nb;
            pq.push({nh, nt, nb});
          }
        }
      }
    }

    int ans = INT_MIN;
    for (int i = 0; i <= m; i++) {
      ans = max(ans, best[x[d]][i]);
    }
    cout << (ans == INT_MIN ? "IMPOSIBLE" : to_string(ans)) << endl;
  }
  return 0;
}
