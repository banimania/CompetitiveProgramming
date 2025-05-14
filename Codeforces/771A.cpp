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
  for (int i = 0; i < n; i++) make_set(dsu, size, i);

  vector<set<int>> friends(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    friends[u].insert(v);
    friends[v].insert(u);
    union_sets(dsu, size, u, v);
  }

  map<int, vector<int>> setNodes;
  for (int i = 0; i < n; i++) {
    setNodes[find_set(dsu, i)].push_back(i);
  }

  for (auto [set, listNodes] : setNodes) {
    for (int i = 0; i < listNodes.size(); i++) {
      int nodeI = listNodes[i];
      for (int j = i + 1; j < listNodes.size(); j++) {
        int nodeJ = listNodes[j];

        if (!friends[nodeI].count(nodeJ)) {
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }

  cout << "YES" << endl;
  return 0;
}
