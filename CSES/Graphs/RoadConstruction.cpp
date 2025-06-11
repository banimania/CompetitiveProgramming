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

  int currComponents = n;
  priority_queue<int> pq;
  pq.push(1);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    if (find_set(dsu, u) != find_set(dsu, v)) currComponents--;
    union_sets(dsu, size, u, v);

    pq.push(size[find_set(dsu, u)]);

    cout << currComponents << " " << pq.top() << endl;
  }
  return 0;
}
