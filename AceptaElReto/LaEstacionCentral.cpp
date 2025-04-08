#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  while (cin >> n >> l) {
    if (!n && !l) break;

    vector<int> grado(n);
    set<int> importantes;

    vector<vector<int>> adj(n);

    for (int i = 0; i < l; i++) {
      vector<int> est;
      int x;
      while (cin >> x) {
        if (!x) break;

        x--;
        est.push_back(x);

        if (!importantes.count(x) && ++grado[x] >= 2) importantes.insert(x); 
      }

      for (int j = 0; j < est.size() - 1; j++) {
        adj[est[j]].push_back(est[(j + 1) % est.size()]);
        adj[est[(j + 1) % est.size()]].push_back(est[j]);
      }
    }

    int bestDist = INT_MAX, bestId = INT_MAX;
    for (int imp : importantes) {
      vector<bool> visited(n, false);
      queue<pair<int, int>> q;
      q.push({imp, 0});
      visited[imp] = true;
      int sum = 0;
      while (!q.empty()) {
        int current = q.front().first;
        int currentDist = q.front().second;
        q.pop();

        if (importantes.count(current)) {
          sum += currentDist;
        }

        for (int neighbour : adj[current]) {
          if (!visited[neighbour]) {
            visited[neighbour] = true;
            q.push({neighbour, currentDist + 10});
          }
        }
      }

      bool todosVisitados = true;
      for (int imp2 : importantes) {
        if (!visited[imp2]) {
          todosVisitados = false;
          break;
        }
      }

      if (!todosVisitados) sum = INT_MAX;

      if (sum < bestDist) {
        bestId = imp + 1;
        bestDist = sum;
      } else if (sum == bestDist) {
        if (imp + 1 < bestId) {
          bestId = imp + 1;
        }
      }
    }

    cout << bestId << endl;
  }
  return 0;
}
