#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, cost;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  while (cin >> n >> c) {
    vector<vector<pair<int, int>>> adj(n), adjT(n);
    for (int i = 0; i < c; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      adj[u].push_back({v, c});
      adjT[v].push_back({u, c});
    }
    
    int o, p;
    cin >> o >> p;
    o--;

    vector<int> distToHouse(n, INT_MAX);
    priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
      return a.cost > b.cost;
    });
    pq.push({o, 0});
    distToHouse[o] = 0;

    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      if (curr.cost > distToHouse[curr.pos]) continue;

      for (pair<int, int> e : adj[curr.pos]) {
        if (curr.cost + e.second < distToHouse[e.first]) {
          distToHouse[e.first] = curr.cost + e.second;
          pq.push({e.first, curr.cost + e.second});
        }
      }
    }

    vector<int> distToOffice(n, INT_MAX);
    pq.push({o, 0});
    distToOffice[o] = 0;
    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      if (curr.cost > distToOffice[curr.pos]) continue;

      for (pair<int, int> e : adjT[curr.pos]) {
        if (curr.cost + e.second < distToOffice[e.first]) {
          distToOffice[e.first] = curr.cost + e.second;
          pq.push({e.first, curr.cost + e.second});
        }
      }
    }

    bool possible = true;
    int ans = 0;
    for (int i = 0; i < p; i++) {
      int x;
      cin >> x;
      x--;

      if (distToHouse[x] == INT_MAX || distToOffice[x] == INT_MAX) possible = false;

      if (possible) ans += distToHouse[x] + distToOffice[x];
    }

    cout << (possible ? to_string(ans) : "Imposible") << endl;
  }
  return 0;
}
