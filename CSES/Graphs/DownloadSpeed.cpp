#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll bfs(int s, int t, vector<vector<int>> &adj, vector<vector<ll>> &capacity, vector<int> &prev) {
  for (int i = 0; i < prev.size(); i++) prev[i] = -1;
  prev[s] = -2;
  queue<pair<int, ll>> q;
  q.push({s, LLONG_MAX});

  while (!q.empty()) {
    int curr = q.front().first;
    ll flow = q.front().second;
    q.pop();

    for (int neighbour : adj[curr]) {
      if (prev[neighbour] == -1 && capacity[curr][neighbour]) {
        prev[neighbour] = curr;
        ll newFlow = min(flow, capacity[curr][neighbour]);

        if (neighbour == t) return newFlow;

        q.push({neighbour, newFlow});
      }
    }
  }

  return 0;
}

ll maxFlow(int s, int t, vector<vector<int>> &adj, vector<vector<ll>> &capacity) {
  ll flow = 0;
  vector<int> prev(adj.size());
  ll currFlow;

  while (currFlow = bfs(s, t, adj, capacity, prev)) {
    flow += currFlow;
    ll curr = t;
    while (curr != s) {
      capacity[prev[curr]][curr] -= currFlow;
      capacity[curr][prev[curr]] += currFlow;
      curr = prev[curr];
    }
  }

  return flow;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n);
  vector<vector<ll>> capacity(n, vector<ll>(n));
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;

    capacity[a][b] += c;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  cout << maxFlow(0, n - 1, adj, capacity) << endl;
  return 0;
}
