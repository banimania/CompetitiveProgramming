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

struct Edge {
  int u, v, c;
};

int main() {
  int n, c;
  while (cin >> n >> c) {
    priority_queue<Edge, vector<Edge>, function<bool(Edge, Edge)>> pq([](const Edge &a, const Edge &b) {
      return a.c > b.c;
    });

    vector<int> dsu(n), size(n);
    for (int i = 0; i < n; i++) {
      make_set(dsu, size, i);
    }

    for (int i = 0; i < c; i++) {
      int u, v, c;
      cin >> u >> v >> c;
      u--, v--;

      pq.push({u, v, c});
    }

    int totalCost = 0;
    while (!pq.empty()) {
      Edge current = pq.top();
      pq.pop();

      if (find_set(dsu, current.u) != find_set(dsu, current.v)) {
        totalCost += current.c;
        union_sets(dsu, size, current.u, current.v);
      }
    }

    bool posible = true;
    for (int i = 0; i < n - 1; i++) {
      if (find_set(dsu, i) != find_set(dsu, i + 1)) {
        cout << "Imposible" << endl;
        posible = false;
        break;
      }
    }

    if (posible) cout << totalCost << endl;

  }
  
  return 0;
}
