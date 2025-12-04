#include <bits/stdc++.h>
using namespace std;

struct State {
  int n;
  int cost;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int np, nc;
  while (cin >> np >> nc) {
    vector<vector<pair<int, int>>> adj(np);
    for (int i = 0; i < nc; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      adj[u].push_back({v, c});
      adj[v].push_back({u, c});
    }

    unordered_map<int, vector<int>> dist;
    int c;
    cin >> c;
    for (int x = 0; x < c; x++) {
      int npa;
      cin >> npa;

      unordered_set<int> pas;
      vector<int> pasV(npa);
      for (int i = 0; i < npa; i++) {
        int p;
        cin >> p;
        p--;
        pas.insert(p);
        pasV[i] = p;

        if (!dist.count(p)) {
          dist[p] = vector<int>(np, INT_MAX);

          priority_queue<State, vector<State>, function<bool(const State&, const State&)>> pq([](const State &a, const State &b) {
            return a.cost > b.cost;
          });
          dist[p][p] = 0;
          pq.push({p, 0});
          while (!pq.empty()) {
            State curr = pq.top();
            pq.pop();

            int u = curr.n;

            if (dist[p][u] < curr.cost) continue;

            for (const pair<int, int> &edge: adj[u]) {
              int v = edge.first;
              int c = edge.second;

              if (dist[p][v] > dist[p][u] + c) {
                dist[p][v] = dist[p][u] + c;
                pq.push({v, dist[p][u] + c});
              }
            }
          }
        }
      }

      int ans = INT_MAX;
      int pans = INT_MAX;
      for (int s = 0; s < np; s++) {
        if (!pas.count(s)) {
          vector<vector<int>> dp(npa + 1, vector<int>(1 << npa, INT_MAX));

          for (int j = 0; j < npa; j++) {
            dp[j][1 << j] = dist[pasV[j]][s];
          }

          for (int j = 0; j < (1 << npa); j++) {
            for (int u = 0; u < npa; u++) {
              if (!(j & (1 << u))) continue;
              for (int v = 0; v < npa; v++) {
                if (j & (1 << v)) continue;
                dp[v][j | (1 << v)] = min(dp[v][j | (1 << v)], dp[u][j] + dist[pasV[u]][pasV[v]]);
              }
            }
          }

          int localAns = INT_MAX;
          for (int j = 0; j < npa; j++) {
            if (dp[j][(1 << npa) - 1] != INT_MAX) {
              localAns = min(localAns, dp[j][(1 << npa) - 1] + dist[pasV[j]][s]);
            }
          }

          if (localAns < ans) {
            ans = localAns;
            pans = s;
          } else if (localAns == ans) {
            if (pans > s) pans = s;
          }
        }
      }

      cout << pans + 1 << " " << ans << "\n";

    }
    cout << "---\n";
  }
  return 0;
}
