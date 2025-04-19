// https://cses.fi/problemset/task/1132

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;

    a--, b--;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int u = -1;

  queue<int> q;
  vector<bool> visited(n);

  q.push(0);
  visited[0] = true;
  while (!q.empty()) {
    u = q.front();
    q.pop();

    for (int neighbour : adj[u]) {
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        q.push(neighbour);
      }
    }
  }

  int v = -1;

  visited = vector<bool>(n);

  vector<int> distU(n);

  q.push(u);
  visited[u] = true;
  distU[u] = 0;
  while (!q.empty()) {
    v = q.front();
    q.pop();

    for (int neighbour : adj[v]) {
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        q.push(neighbour);
        distU[neighbour] = distU[v] + 1;
      }
    }
  }
  
  vector<int> distV(n);

  visited = vector<bool>(n);

  q.push(v);
  visited[v] = true;
  distV[v] = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int neighbour : adj[curr]) {
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        q.push(neighbour);
        distV[neighbour] = distV[curr] + 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << max(distU[i], distV[i]) << " ";
  }
  cout << endl;

  return 0;
}
