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
  int n;
  while (cin >> n && n) {
    vector<int> dsu(n), size(n);
    for (int i = 0; i < n; i++) {
      make_set(dsu, size, i);
    }
    int cnt = 0;

    int u, v;
    while (cin >> u >> v) {
      if (!u && !v) break;
      u--, v--;

      if (find_set(dsu, u) != find_set(dsu, v)) {
        union_sets(dsu, size, u, v);
      } else cnt++;
    }

    cout << cnt << endl;
  }

  return 0;
}
