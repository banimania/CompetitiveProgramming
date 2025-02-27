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
  int n, m;
  cin >> n >> m;

  vector<int> dsu(n), size(n);
  for (int i = 0; i < n; i++) {
    make_set(dsu, size, i);
  }

  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;

    int first = -1;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      x--;

      if (first == -1) {
        first = x;
        continue;
      }

      if (find_set(dsu, x) != find_set(dsu, first)) union_sets(dsu, size, x, first);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << size[find_set(dsu, i)] << " ";
  }
  cout << endl;

  return 0;
}
