#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue<pair<int, int>> q;
  q.push({s, INT_MAX});

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && capacity[cur][next]) {
        parent[next] = cur;
        int new_flow = min(flow, capacity[cur][next]);
        if (next == t) return new_flow;
        q.push({next, new_flow});
      }
    }
  }

  return 0;
}

int maxflow(int s, int t) {
  int flow = 0;
  vector<int> parent(n);
  int new_flow;

  while (new_flow = bfs(s, t, parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      capacity[prev][cur] -= new_flow;
      capacity[cur][prev] += new_flow;
      cur = prev;
    }
  }

  return flow;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c, p;
  while (cin >> c >> p) {
    n = c + p + 2;
    adj = vector<vector<int>>(n);
    capacity = vector<vector<int>>(n, vector<int>(n, 0));
    
    vector<int> cat(c);
    for (int i = 0; i < c; i++) {
      cin >> cat[i];
      int nCat = 1 + p + i;
      adj[nCat].push_back(n - 1);
      capacity[nCat][n - 1] = cat[i];
      adj[n - 1].push_back(nCat);
    }

    for (int i = 0; i < p; i++) {
      int x;

      int nProblema = i + 1;

      adj[0].push_back(nProblema);
      adj[nProblema].push_back(0);
      capacity[0][nProblema] = 1;

      while (cin >> x && x) {
        int nCat = 1 + p + (x - 1);
        adj[nProblema].push_back(nCat);
        adj[nCat].push_back(nProblema);
        capacity[nProblema][nCat] = 1;
      }
    }

    cout << maxflow(0, n - 1) << "\n";
  }

  return 0;
}
