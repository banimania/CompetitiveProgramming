#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, dist;
};

int dijkstra(vector<vector<pair<int, int>>> &adj, int src, int target) {
  priority_queue<State, vector<State>, function<bool(const State&, const State&)>> pq([](const State &a, const State &b) {
    return a.dist > b.dist;
  });

  vector<int> minCost(adj.size(), INT_MAX);
  minCost[src] = 0;

  pq.push({src, 0});
  
  while (!pq.empty()) {
    State curr = pq.top();
    pq.pop();

    if (curr.dist > minCost[curr.pos]) continue;

    if (curr.pos == target) break;

    for (const pair<int, int> &edge: adj[curr.pos]) {
      if (minCost[edge.first] > curr.dist + edge.second) {
        minCost[edge.first] = curr.dist + edge.second;
        pq.push({edge.first, curr.dist + edge.second});
      }
    }
  }

  return minCost[target];
}

int main() {
  int n, c;
  while (cin >> n >> c) {
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < c; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;
      
      adj[u].push_back({v, c});
      adj[v].push_back({u, c});
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int src, target;
      cin >> src >> target;
      src--, target--;

      int v = dijkstra(adj, src, target);

      cout << (v == INT_MAX ? "NO LLEGA" : to_string(v)) << endl;
    }

    cout << "---" << endl;
  }
  return 0;
}
