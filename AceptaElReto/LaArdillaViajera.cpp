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
  int n, m, k, x;
  while (cin >> n >> m >> k >> x) {
    vector<bool> map((n + 1) * (m + 1));
    map[0] = true;
    map[(n + 1) * (m + 1) - 1] = true;

    vector<int> dirs = {1, -1, -(m + 1), (m + 1)};

    vector<int> dsu((n + 1) * (m + 1)), size((n + 1) * (m + 1));
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        int val = (i * (m + 1)) + j;

        make_set(dsu, size, val);
      }
    }

    vector<pair<int, int>> arboles(x);
    for (int i = 0; i < x; i++) {
      cin >> arboles[i].first >> arboles[i].second;
    }

    int curr = x - 1;
    while (curr >= 0) {
      int pos = arboles[curr].first * (m + 1) + arboles[curr].second;
      map[pos] = true;

      for (int i = max(-k + arboles[curr].first, 0); i <= min(k + arboles[curr].first, n); i++) {
        for (int j = max(-k + arboles[curr].second, 0); j <= min(k + arboles[curr].second, m); j++) {
          int npos = i * (m + 1) + j;
          int distI = abs(i - arboles[curr].first), distJ = abs(j - arboles[curr].second);
          if (map[npos] && sqrt(distI * distI + distJ * distJ) <= k) union_sets(dsu, size, npos, pos);
        }
      }

      if (find_set(dsu, 0) == find_set(dsu, (n + 1) * (m + 1) - 1)) {
        cout << arboles[curr].first << " " << arboles[curr].second << endl;
        break;
      }
      curr--;

    }

    if (find_set(dsu, 0) != find_set(dsu, (n + 1) * (m + 1) - 1)) cout << "NUNCA SE PUDO" << endl;
  }

  return 0;
}
