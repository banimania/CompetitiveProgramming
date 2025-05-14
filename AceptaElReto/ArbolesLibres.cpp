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
    int a;
    cin >> a;

    vector<int> dsu(v), size(v);
    for (int i = 0; i < v; i++) make_set(dsu, size, i);

    bool arbol = true;
    
    for (int i = 0; i < a; i++) {
      int u, v;
      cin >> u >> v;

      if (find_set(dsu, u) == find_set(dsu, v)) {
        arbol = false;
      }
      union_sets(dsu, size, u, v);
    }

    if (arbol) {
      for (int i = 1; i < v; i++) {
        if (find_set(dsu, i) != find_set(dsu, i - 1)) {
          arbol = false;
          break;
        }
      }
    }

    cout << (arbol ? "SI" : "NO") << endl;
  }
  return 0;
}
