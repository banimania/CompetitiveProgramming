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

int main() {
  int v;
  while (cin >> v) {
    bool bipartite = true;

    vector<int> dsu(2 * v), size(2 * v);
    for (int i = 0; i <  2 * v; i++) make_set(dsu, size, i);
    
    int a;
    cin >> a;

    for (int i = 0; i < a; i++) {
      int x, y;
      cin >> x >> y;

      if (find_set(dsu, x) == find_set(dsu, y)) bipartite = false;

      union_sets(dsu, size, x, y + v);
      union_sets(dsu, size, y, x + v);
    }

    cout << (bipartite ? "SI" : "NO") << endl;
  }
  return 0;
}
