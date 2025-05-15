#include <bits/stdc++.h>
using namespace std;

template<typename T>
void make_set(vector<T> &dsu, vector<T> &size, T v) {
  dsu[v] = v;
  size[v] = 1;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v]) return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, vector<T> &size, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    dsu[b] = a;
    size[a] += size[b];
  }
}

bool checkCycle(int curr, vector<vector<int>> &adj, vector<int> &visited) {
  visited[curr] = 1;
  for (int neighbour : adj[curr]) {
    if (visited[neighbour] == 1) {
      return true;
    }
    if (!visited[neighbour]) {
      if (checkCycle(neighbour, adj, visited)) return true;
    }
  }
  visited[curr] = 2;
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m) {
    vector<vector<int>> adj(n);

    vector<int> dsu(n), size(n);
    for (int i = 0; i < n; i++) make_set(dsu, size, i);

    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
      int u, v;
      char symb;
      cin >> u >> symb >> v;

      u--, v--;
      if (symb == '>') {
        edges.push_back({u, v});
      } else if (symb == '=') {
        union_sets(dsu, size, u, v);
      } else {
        edges.push_back({v, u});
      }
    }

    for (int i = 0; i < edges.size(); i++) {
      int u = edges[i].first, v = edges[i].second;

      adj[find_set(dsu, u)].push_back(find_set(dsu, v));
    }

    unordered_set<int> sets;
    for (int i = 0; i < n; i++) {
      sets.insert(find_set(dsu, i));
    }

    vector<int> visited(n);

    bool trampas = false;
    for (int i : sets) {
      if (!visited[i]) {
        if (checkCycle(i, adj, visited)) {
          trampas = true;
          break;
        }
      }

      if (trampas) break;
    }

    cout << (trampas ? "TRAMPAS" : "DESCONFIADO") << endl;
  }
  return 0;
}
