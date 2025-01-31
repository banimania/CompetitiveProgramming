#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

const ll MOD = 1e9 + 7;

#define TESTCASES false

void solve() {
  vector<vector<char>> a(8, vector<char>(8));

  REP (i, 0, 8) {
    REP (j, 0, 8) {
      cin >> a[i][j];
    }
  }

  set<ll> filas = {0, 1, 2, 3, 4, 5, 6, 7};
  set<ll> columnas = {0, 1, 2, 3, 4, 5, 6, 7};

  ll ans = 0;
  
  REP (i, 0, a.size()) {
    REP (j, 0, a.size()) {
      if (a[i][j] == 'W') {
        filas.erase(i);
        columnas.erase(j);
      }
    }
  }

  if (filas.size() + columnas.size() == 16) {
    cout << 8 << endl;
    return;
  }

  cout << filas.size() + columnas.size() << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
