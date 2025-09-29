#include <bits/stdc++.h>
using namespace std;

template<typename T>
void make_set(vector<T> &dsu, vector<T> &size, vector<bool> &cycle, T v) {
  dsu[v] = v;
  size[v] = 1;
  cycle[v] = false;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v]) return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, vector<T> &size, vector<bool> &cycle, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    dsu[b] = a;
    size[a] += size[b];
    cycle[a] = cycle[a] | cycle[b];
  } else {
    cycle[a] = true;
  }
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector<int> dsu(n), size(n);
    vector<bool> cycle(n);
    for (int i = 0; i < n; i++) {
      make_set(dsu, size, cycle, i);
    }

    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;

      union_sets(dsu, size, cycle, u, v);
    }

    unordered_set<int> seenSets;
    int aislados = 0, arboles = 0, ciclos = 0;
    for (int i = 0; i < n; i++) {
      int a = find_set(dsu, i);
      if (!seenSets.count(a)) {
        seenSets.insert(a);

        if (size[a] == 1) aislados++;
        else if (!cycle[a]) arboles++;
        else ciclos++;
      }
    }

    cout << aislados << " " << arboles << " " << ciclos << endl;
  }
  return 0;
}
