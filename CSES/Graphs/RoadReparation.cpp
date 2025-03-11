#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

struct Road {
  int u, v, cost;
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> dsu(n), size(n);
  for (int i = 0; i < n; i++) {
    make_set(dsu, size, i);
  }

  priority_queue<Road, vector<Road>, function<bool(Road, Road)>> pq([](const Road &a, const Road &b) {
    return a.cost > b.cost;
  });

  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    u--, v--;

    pq.push({u, v, c});
    pq.push({v, u, c});
  }

  ll cost = 0;

  while (!pq.empty()) {
    Road current = pq.top();
    pq.pop();

    if (find_set(dsu, current.u) != find_set(dsu, current.v)) {
      union_sets(dsu, size, current.u, current.v);
      cost += current.cost;
    }
  }

  for (int i = 0; i < n - 1; i++) {
    if (find_set(dsu, i) != find_set(dsu, i + 1)) {
      cout << "IMPOSSIBLE" << endl;
      return 0;
    }
  }

  cout << cost << endl;

  return 0;
}
