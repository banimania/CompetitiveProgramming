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

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> dsu(n), size(n);
  for (int i = 0; i < n; i++) make_set(dsu, size, i);

  int maxSize = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    union_sets(dsu, size, u, v);
    maxSize = max(maxSize, size[find_set(dsu, u)]);
  }

  cout << maxSize << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
