#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define TESTCASES 1

struct Edge {
  int u, v, m;
};

struct Query {
  int a, b, e, i;
  bool answer = false;
};

struct DSU {
  vector<int> parent, size;

  DSU(int n) {
    parent = vector<int>(n);
    size = vector<int>(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    if (x == parent[x]) return x;
    else return parent[x] = find(parent[x]);
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

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> heights(n);

  for (int i = 0; i < n; i++) {
    cin >> heights[i];
  }

  vector<Edge> edges;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    edges.push_back({u, v, max(heights[v], heights[u])});
  }

  int q;
  cin >> q;
  vector<Query> queries(q);
  for (int i = 0; i < q; i++) {
    int a, b, e;
    cin >> queries[i].a >> queries[i].b >> queries[i].e;
    queries[i].i = i;
    queries[i].a--;
    queries[i].b--;
  }

  sort(queries.begin(), queries.end(), [&](const Query &a, const Query &b) {
    return heights[a.a] + a.e < heights[b.a] + b.e;
  });

  sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
    return a.m < b.m;
  });

  DSU dsu(n);

  int nextEdge = 0;
  for (int i = 0; i < queries.size(); i++) {
    while (nextEdge < edges.size() && edges[nextEdge].m <= heights[queries[i].a] + queries[i].e) {
      dsu.unite(edges[nextEdge].u, edges[nextEdge].v);
      nextEdge++;
    }

    queries[i].answer = dsu.find(queries[i].a) == dsu.find(queries[i].b);
  }

  sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) {
    return a.i < b.i;
  });

  for (int i = 0; i < q; i++) {
    cout << (queries[i].answer ? "YES" : "NO") << endl;
  }

  cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
