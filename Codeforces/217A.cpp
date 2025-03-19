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
  cin >> n;

  vector<int> dsu(n), size(n);
  for (int i = 0; i < n; i++) make_set(dsu, size, i);

  vector<pair<int, int>> drifts(n);
  for (int i = 0; i < n; i++) {
    cin >> drifts[i].first >> drifts[i].second;
  }

  int cnt = 0;
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (drifts[i].first == drifts[j].first || drifts[i].second == drifts[j].second) {
        union_sets(dsu, size, i, j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (find_set(dsu, i) != find_set(dsu, 0)) {
      union_sets(dsu, size, i, 0);
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}
