#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, dist;
};

void dfs(int curr, vector<multiset<pair<int, int>>> &prev, int &totalDist, vector<bool> &visited) {
  for (auto [neighbour, cost] : prev[curr]) {
    totalDist += cost;
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      dfs(neighbour, prev, totalDist, visited);
    }
  }
}

int main() {
  int p, t;
  cin >> p >> t;

  vector<vector<pair<int, int>>> adj(p);

  for (int i = 0; i < t; i++) {
    int p1, p2, l;
    cin >> p1 >> p2 >> l;

    adj[p1].push_back({p2, l});
    adj[p2].push_back({p1, l});
  }

  vector<multiset<pair<int, int>>> prev(p);
  vector<int> minDist(p, INT_MAX);

  priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
    return a.dist > b.dist;
  });

  pq.push({0, 0});
  minDist[0] = 0;

  while (!pq.empty()) {
    State curr = pq.top();
    pq.pop();

    if (curr.dist > minDist[curr.pos]) continue;

    for (auto [neighbour, cost] : adj[curr.pos]) {
      int newDist = curr.dist + cost;

      if (newDist < minDist[neighbour]) {
        minDist[neighbour] = newDist;
        pq.push({neighbour, newDist});

        prev[neighbour] = {{curr.pos, cost}};
      } else if (newDist == minDist[neighbour]) {
        prev[neighbour].insert({curr.pos, cost});
      }
    }
  }

  int totalDist = 0;

  vector<bool> visited(p);
  visited[p - 1] = true;
  dfs(p - 1, prev, totalDist, visited);

  cout << totalDist * 2 << endl;
  
  return 0;
}
