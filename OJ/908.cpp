#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
  vector<int> parent, size;
  int n;

  DSU(int n) {
    this->n = n;
    this->parent = vector<int>(n);
    this->size = vector<int>(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (size[b] > size[a]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
};

struct Edge {
  int u, v, cost;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  bool first = true;
  int n;
  while (cin >> n) {
    if (first) {
      first = false;
    } else {
      cout << "\n";
    }
    vector<Edge> edges;
    int ans1 = 0;
    for (int i = 0; i < n - 1; i++) {
      int u, v, cost;
      cin >> u >> v >> cost;
      u--, v--;
      ans1 += cost;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
      int u, v, cost;
      cin >> u >> v >> cost;
      u--, v--;

      edges.push_back({u, v, cost});
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int u, v, cost;
      cin >> u >> v >> cost;
      u--, v--;

      edges.push_back({u, v, cost});
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
      return a.cost < b.cost;
    });

    int ans2 = 0;
    DSU dsu(n);
    for (int i = 0; i < (int) edges.size(); i++) {
      Edge edge = edges[i];

      int u = edge.u;
      int v = edge.v;
      int c = edge.cost;

      if (dsu.find(u) == dsu.find(v)) continue;

      dsu.unite(u, v);

      ans2 += c;
    }

    cout << ans1 << "\n" << ans2 << "\n";
  }
  return 0;
}
