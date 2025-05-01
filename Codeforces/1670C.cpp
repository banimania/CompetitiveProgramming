#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

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

  map<int, int> indexA, indexB;
  vector<int> a(n), b(n), d(n), dsu(n), size(n);
  for (int i = 0; i < n; i++) cin >> a[i], indexA[a[i]] = i;
  for (int i = 0; i < n; i++) cin >> b[i], indexB[b[i]] = i;
  for (int i = 0; i < n; i++) cin >> d[i];
  for (int i = 0; i < n; i++) make_set(dsu, size, i);

  for (int i = 0; i < n; i++) {
    if (a[i] == b[i]) d[i] = a[i];
    if (d[i] != 0) {
      if (d[i] == a[i]) {
        d[indexA[b[i]]] = b[i];
      } else {
        d[indexB[a[i]]] = a[i];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (d[i] == 0) {
      union_sets(dsu, size, indexA[a[i]], indexB[a[i]]);
      union_sets(dsu, size, indexB[b[i]], indexA[b[i]]);
    }
  }

  ll ans = 1;
  set<int> seen;

  for (int i = 0; i < n; i++) {
    if (d[i] != 0) {
      seen.insert(find_set(dsu, i));
    }
  }

  for (int i = 0; i < n; i++) {
    if (d[i] == 0) {
      if (!seen.count(find_set(dsu, i))) {
        seen.insert(find_set(dsu, i));
        ans = (ans * 2) % MOD;
      }
    }
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
