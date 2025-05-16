#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, time;
};

struct Edge {
  int u, v, cost;
  bool operator<(const Edge &other) const {
    if (u != other.u) return u < other.u;
    if (v != other.v) return v < other.v;
    return cost < other.cost;
  }
};

int main() {
  int ni, nc;
  while (cin >> ni >> nc) {

    vector<vector<pair<int, int>>> adj(ni);

    for (int i = 0; i < nc; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      adj[u].push_back({v, c});
      adj[v].push_back({u, c});
    }

    priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
      return a.time > b.time;
    });

    vector<int> minT(ni, INT_MAX);
    minT[0] = 0;

    vector<set<pair<int, int>>> prev(ni);
    pq.push({0, 0});
    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      if (curr.time > minT[curr.pos]) {
        if (curr.pos == ni - 1) break;
        continue;
      }

      for (const pair<int, int> &pair : adj[curr.pos]) {
        int neighbour = pair.first;
        int newTime = curr.time + pair.second;

        if (minT[neighbour] > newTime) {
          minT[neighbour] = newTime;
          pq.push({neighbour, newTime});
          prev[neighbour] = {{curr.pos, pair.second}};
        } else if (minT[neighbour] == newTime) {
          prev[neighbour].insert({curr.pos, pair.second});
        }
      }
    }

    while (!pq.empty()) pq.pop();

    set<Edge> banned;
    stack<int> st;
    st.push(ni - 1);
    vector<bool> visited(ni);
    visited[ni - 1] = true;
    while (!st.empty()) {
      int curr = st.top();
      st.pop();
      for (const pair<int, int> &pair : prev[curr]) {
        banned.insert({min(curr, pair.first), max(curr, pair.first), pair.second});
        if (!visited[pair.first]) {
          visited[pair.first] = true;
          st.push(pair.first);
        }
      }
    }

    fill(minT.begin(), minT.end(), INT_MAX);
    minT[0] = 0;

    pq.push({0, 0});
    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      if (curr.pos == ni - 1) break;
      if (curr.time > minT[curr.pos]) continue;

      for (const pair<int, int> &pair : adj[curr.pos]) {
        int neighbour = pair.first;
        int newTime = curr.time + pair.second;

        if (banned.count({min(curr.pos, neighbour), max(curr.pos, neighbour), pair.second})) continue;
        if (minT[neighbour] > newTime) {
          minT[neighbour] = newTime;
          pq.push({neighbour, newTime});
        }
      }
    }
    
    cout << (minT[ni - 1] == INT_MAX ? "IMPOSIBLE" : to_string(minT[ni - 1])) << endl;
  }
  return 0;
}
