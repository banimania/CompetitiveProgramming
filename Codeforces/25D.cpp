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
  int n;
  cin >> n;

  vector<int> dsu(n), size(n);
  for (int i = 0; i < n; i++) {
    make_set(dsu, size, i);
  }

  vector<pair<int, int>> extraEdges;

  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    if (find_set(dsu, u) == find_set(dsu, v)) {
      extraEdges.push_back({u, v});
    }

    union_sets(dsu, size, u, v);
  }

  vector<int> rep;
  set<int> setsSeen;
  for (int i = 0; i < n; i++) {
    int set = find_set(dsu, i);
    if (!setsSeen.count(set)) {
      setsSeen.insert(set);
      rep.push_back(i);
    }
  }

  cout << rep.size() - 1 << endl;
  for (int i = 0; i < rep.size() - 1; i++) {
    int u = rep[i];
    int v = rep[(i + 1) % rep.size()];

    cout << extraEdges[i].first + 1 << " " << extraEdges[i].second + 1 << " " << u + 1 << " " << v + 1 << endl;
  }

}

int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
