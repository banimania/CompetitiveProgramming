#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int curr, vector<vector<int>> &adj, vector<vector<ll>> &capacity, vector<bool> &visited) {
  for (int neighbour : adj[curr]) {
    if (!visited[neighbour] && capacity[curr][neighbour]) {
      visited[neighbour] = true;
      dfs(neighbour, adj, capacity, visited);
    }
  }
}

ll bfs(int s, int t, vector<vector<int>> &adj, vector<vector<ll>> &capacity, vector<int> &prev) {
  for (int i = 0; i < prev.size(); i++) prev[i] = -1;
  prev[s] = -2;

  queue<pair<int, ll>> q;
  q.push({s, INT_MAX});

  while (!q.empty()) {
    int curr = q.front().first;
    ll currFlow = q.front().second;
    q.pop();

    for (int neighbour : adj[curr]) {
      if (capacity[curr][neighbour] && prev[neighbour] == -1) {
        ll newFlow = min(currFlow, capacity[curr][neighbour]);
        prev[neighbour] = curr;

        if (neighbour == t) return newFlow;

        q.push({neighbour, newFlow});
      }
    }
  }
  return 0;
}

ll maxFlow(int s, int t, vector<vector<int>> &adj, vector<vector<ll>> &capacity) {
  ll flow = 0;
  vector<int> prev(adj.size(), -1);
  ll currFlow;

  while (currFlow = bfs(s, t, adj ,capacity, prev)) {
    flow += currFlow;

    int curr = t;
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
    int a, b;
    cin >> a >> b;
    a--, b--;

    adj[a].push_back(b);
    adj[b].push_back(a);

    capacity[a][b] += 1;
    capacity[b][a] += 1;
  }

  vector<vector<ll>> originalCapacity(capacity.begin(), capacity.end());

  cout << maxFlow(0, n - 1, adj, capacity) << endl;

  vector<bool> visited(n, false);

  visited[0] = true;
  dfs(0, adj, capacity, visited);

  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      for (int neighbour : adj[i]) {
        if (!visited[neighbour] && originalCapacity[i][neighbour]) {
          cout << i + 1 << " " << neighbour + 1 << endl;
        }
      }
    }
  }

  return 0;
}
