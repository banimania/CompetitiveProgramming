#include <bits/stdc++.h>
using namespace std;

struct State {
  int pos, dist, calles;
};

int main() {
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
      int start, end;
      cin >> start >> end;
      start--, end--;

      vector<int> minCalles(n, INT_MAX), minDist(n, INT_MAX);
      minCalles[start] = 0, minDist[start] = 0;

      int nCalles = INT_MAX;

      queue<int> q;
      q.push(start);
      while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == end) {
          break;
        }

        for (pair<int, int> neighbourStreet : adj[curr]) {
          int neighbour = neighbourStreet.first;
          if (minCalles[neighbour] > minCalles[curr] + 1) {
            minCalles[neighbour] = minCalles[curr] + 1;
            q.push(neighbour);
          }
        }
      }

      priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
        if (a.dist == b.dist) return a.calles > b.calles;
        return a.dist > b.dist;
      });
      pq.push({start, 0, 0});
      while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        if (curr.pos == end && curr.dist == minDist[end]) {
          nCalles = min(nCalles, curr.calles);
          break;
        }

        for (pair<int, int> neighbourStreet : adj[curr.pos]) {
          int neighbour = neighbourStreet.first;
          int cost = neighbourStreet.second;

          if (minDist[neighbour] > curr.dist + cost) {
            minDist[neighbour] = curr.dist + cost;
            pq.push({neighbour, curr.dist + cost, curr.calles + 1});
          }
        }
      }

      if (minCalles[end] == INT_MAX || minDist[end] == INT_MAX) {
        cout << "SIN CAMINO" << endl;
      } else {
        cout << minDist[end] << " " << (minCalles[end] == nCalles ? "SI" : "NO") << endl;
      }
    }
    cout << "----" << endl;
  }
  return 0;
}
