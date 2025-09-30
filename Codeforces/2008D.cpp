#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, size, blacks;

  DSU(int n, string &s) {
    parent = vector<int>(n);
    size = vector<int>(n, 1);
    blacks = vector<int>(n);
    for (int i = 0; i < n ; i++) parent[i] = i;
    for (int i = 0; i < n; i++) blacks[i] = (s[i] == '0' ? 1 : 0);
  }

  int find(int n) {
    if (parent[n] == n) return n;
    return parent[n] = find(parent[n]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
    blacks[a] += blacks[b];
  }
};

void solve() {
  int n;
  cin >> n;

  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
  
  string s;
  cin >> s;

  DSU dsu(n, s);

  for (int i = 0; i < n; i++) {
    dsu.unite(i, p[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << dsu.blacks[dsu.find(i)] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
