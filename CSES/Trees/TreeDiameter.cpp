// https://cses.fi/problemset/task/1131

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
  
  vector<bool> visited(n);
  queue<int> q;
  q.push(0);
  visited[0] = true;

  int u = 0;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    u = curr;

    for (int neighbour : adj[curr]) {
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        q.push(neighbour);
      }
    }
  }
  
  visited = vector<bool>(n, false);
  visited[u] = true;

  vector<int> dist(n);
  int v = 0;

  q.push(u);
  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    v = curr;

    for (int neighbour : adj[curr]) {
      if (!visited[neighbour]) {
        visited[neighbour] = true;
        q.push(neighbour);

        dist[neighbour] = dist[curr] + 1;
      }
    }
  }

  cout << dist[v] << endl;

  return 0;
}
