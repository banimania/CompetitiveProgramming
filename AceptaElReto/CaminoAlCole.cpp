#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, cost;
};

void buildAdj(int curr, vector<vector<int>> &prev, vector<vector<int>> &adj, vector<bool> &visited) {
  for (int back : prev[curr]) {
    adj[back].push_back(curr);
    if (!visited[back]) {
      visited[back] = true;
      buildAdj(back, prev, adj, visited);
    }
  }
}

void topoSort(int curr, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &topo) {
  for (int neighbour : adj[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      topoSort(neighbour, adj, visited, topo);
    }
  }

  topo.push(curr);
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> prev(n);

    for (int i = 0; i < m; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      adj[u].push_back({v, c});
      adj[v].push_back({u, c});
    }

    vector<int> minDist(n, INT_MAX);
    priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
      return a.cost > b.cost;
    });

    minDist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      for (pair<int, int> edge : adj[curr.pos]) {
        if (curr.cost + edge.second < minDist[edge.first]) {
          minDist[edge.first] = curr.cost + edge.second;
          prev[edge.first] = {curr.pos};
          pq.push({edge.first, minDist[edge.first]});
        } else if (curr.cost + edge.second == minDist[edge.first]) {
          prev[edge.first].push_back(curr.pos);
        }
      }
    }

    vector<vector<int>> realAdj(n);
    vector<bool> visited(n);

    visited[n - 1] = true;
    buildAdj(n - 1, prev, realAdj, visited);

    fill(visited.begin(), visited.end(), false);

    stack<int> topo;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        visited[i] = true;
        topoSort(i, realAdj, visited, topo);
      }
    }

    vector<int> dp(n);
    dp[0] = 1;

    while (!topo.empty()) {
      int i = topo.top();
      topo.pop();

      for (int neighbour : realAdj[i]) {
        dp[neighbour] += dp[i];
      }
    }

    cout << dp[n - 1] << endl;
  }
  return 0;
}
