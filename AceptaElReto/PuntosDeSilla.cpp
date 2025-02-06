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

struct Elemento {
  int minFila, maxFila, minColumna, maxColumna;
};

void solve2(int f, int c) {
  vector<vector<int>> m(f, vector<int>(c));

  REP (i, 0, f) {
    REP (j, 0, c) {
      cin >> m[i][j];
    }
  }

  vector<vector<Elemento>> a(f, vector<Elemento>(c, {INT_MIN, INT_MAX, INT_MIN, INT_MAX}));
  REP (i, 0, f) {
    int menor = INT_MAX;
    int mayor = INT_MIN;
    REP (j, 0, c) {
      menor = min(menor, m[i][j]);
      mayor = max(mayor, m[i][j]);
    }

    REP (j, 0, c) {
      a[i][j].minFila = menor;
      a[i][j].maxFila = mayor;
    }
  }
  REP (j, 0, c) {
    int menor = INT_MAX;
    int mayor = INT_MIN;
    REP (i, 0, f) {
      menor = min(menor, m[i][j]);
      mayor = max(mayor, m[i][j]);
    }

    REP (i, 0, f) {
      a[i][j].minColumna = menor;
      a[i][j].maxColumna = mayor;
    }
  }

  REP (i, 0, f) {
    REP (j, 0, c) {
      if ((m[i][j] == a[i][j].minColumna && m[i][j] == a[i][j].maxFila) ||
      (m[i][j] == a[i][j].maxColumna && m[i][j] == a[i][j].minFila)) {
        cout << "SI" << endl;
        return;
      }
    }
  }

  cout << "NO" << endl;
}

void solve() {
  int f, c;
  while (cin >> f >> c) {
    if (!f && !c) return;
    solve2(f, c);
  }
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
