#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> parent, size;
  DSU(int n) {
    parent = vector<int>(n);
    size = vector<int>(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (size[b] > size[a]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }

};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, m;
  while (cin >> m >> n) {
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }

    DSU dsu(n * m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '.') {
          if (i + 1 < n && grid[i + 1][j] == '.') dsu.unite(i * m + j, (i + 1) * m + j);
          if (i - 1 >= 0 && grid[i - 1][j] == '.') dsu.unite(i * m + j, (i - 1) * m + j);

          if (j + 1 < m && grid[i][j + 1] == '.') dsu.unite(i * m + j, i * m + j + 1);
          if (j - 1 >= 0 && grid[i][j - 1] == '.') dsu.unite(i * m + j, i * m + j - 1);
        }
      }
    }

    int aire = dsu.find(0);

    bool ans = false;
    for (int i = 1; i < n - 1 && !ans; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (grid[i][j] == '.' && dsu.find(i * m + j) != aire) {
          ans = true;
          break;
        }
      }
    }

    cout << (ans ? "SI" : "NO") << "\n";
  }
  return 0;
}
