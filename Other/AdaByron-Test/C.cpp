#include <bits/stdc++.h>
using namespace std;

int bfs(vector<vector<int>> &capacity, vector<int> &parent, int start, int end, vector<int> &dirs, int n, int m) {
  for (int i = 0; i < parent.size(); i++) {
    parent[i] = -1;
  }
  parent[start] = -2;

  queue<pair<int, int>> q;
  q.push({start, INT_MAX});

  while (!q.empty()) {
    int curr = q.front().first;
    int flow = q.front().second;
    q.pop();

    if (curr == end) return flow;

    // for (int dir : dirs) {
    //   if ((dir == 1 && curr % m == m - 1) || (dir == -1 && curr % m == 0)) continue;
    //   int newPos = curr + dir;

    //   if (newPos < 0 || newPos >= n * m) continue;

    //   if (parent[newPos] == -1 && capacity[curr][newPos]) {
    //     parent[newPos] = curr;
    //     int newFlow = min(flow, capacity[curr][newPos]);
    //     q.push({newPos, newFlow});
    //   }
    // }
    for (int i = 0; i < capacity.size(); i++) {
      if (parent[i] == -1 && capacity[curr][i]) {
        parent[i] = curr;
        int newFlow = min(flow, capacity[curr][i]);
        q.push({i, newFlow});
      }
    }
  }

  return 0;
}

int maxFlow(vector<vector<int>> &capacity, int start, int end, vector<int> &dirs, int n, int m) {
  int flow = 0;
  vector<int> parent(capacity.size());
  int newFlow;

  while ((newFlow = bfs(capacity, parent, start, end, dirs, n, m))) {
    flow += newFlow;
    int curr = end;
    while (curr != start) {
      int prev = parent[curr];
      capacity[prev][curr] -= newFlow;
      capacity[curr][prev] += newFlow;
      curr = prev;
    }
  }

  return flow;
}

void solve(int tt) {
  cout << "Caso #" << tt << ": ";
  int n, m;
  cin >> n >> m;

  vector<char> a(n * m);
  for (int i = 0; i < n * m; i++) cin >> a[i];

  int nodes = n * m * 2;
  vector<vector<int>> capacity(nodes, vector<int>(nodes, 0));

  int start = -1, end = -1;
  vector<int> dirs = {1, -1, m, -m};

  for (int i = 0; i < n * m; i++) {
    int in = i * 2;
    int out = in + 1;

    if (a[i] != 't') {
      capacity[in][out] = 1;
      
      if (a[i] == 'V') start = out;
      if (a[i] == 'G') end = in;

      for (int dir : dirs) {
        if ((dir == 1 && i % m == m - 1) || (dir == -1 && i % m == 0)) continue;
        int ni = i + dir;
        if (ni >= 0 && ni < n * m && a[ni] != 't') {
          int newIn = ni * 2;
          capacity[out][newIn] = 1;
        }
      }
    }
  }

  if (abs(start - end) == 1 || abs(start - end) == m) {
    cout << "No tiene escapatoria!" << endl;
    return;
  }

  cout << maxFlow(capacity, start, end, dirs, n, m) << endl;
}

int main() {
  int tt;
  cin >> tt;

  for (int i = 1; i <= tt; i++) {
    solve(i);
  }

  return 0;
}
