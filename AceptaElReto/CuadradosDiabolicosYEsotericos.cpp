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

#define TESTCASES false

void solve() {
  ll n;
  while (cin >> n) {
    if (n == 0) return;

    vector<vector<int>> a(n, vector<int>(n));
    set<int> nums;
    REP(i, 0, n) {
      REP(j, 0, n) {
        cin >> a[i][j];
        nums.insert(a[i][j]);
      }
    }

    int cm = 0;
    REP(i, 0, n) cm += a[0][i];

    bool diabolico = true;
    REP(i, 0, n) {
      int sumaFila = 0, sumaCol = 0;
      REP(j, 0, n) {
        sumaFila += a[i][j];
        sumaCol += a[j][i];
      }
      if (sumaFila != cm || sumaCol != cm) {
        diabolico = false;
        break;
      }
    }

    int diag1 = 0, diag2 = 0;
    REP(i, 0, n) {
      diag1 += a[i][i];
      diag2 += a[i][n - 1 - i];
    }
    if (diag1 != cm || diag2 != cm) diabolico = false;

    if (!diabolico) {
      cout << "NO" << endl;
      continue;
    }

    bool cumple = nums.size() == n * n;
    if (cumple) {
      REP(i, 1, n * n + 1) {
        if (!nums.count(i)) {
          cumple = false;
          break;
        }
      }
    }

    if (!cumple) {
      cout << "DIABOLICO" << endl;
      continue;
    }

    int cm2 = 4 * cm / n;
    int sumaEsquinas = a[0][0] + a[0][n - 1] + a[n - 1][0] + a[n - 1][n - 1];
    if (sumaEsquinas != cm2) {
      cout << "DIABOLICO" << endl;
      continue;
    }

    if (n % 2 == 1) {
      int sumaLaterales = a[0][n / 2] + a[n / 2][0] + a[n / 2][n - 1] + a[n - 1][n / 2];
      if (sumaLaterales != cm2 || 4 * a[n / 2][n / 2] != cm2) {
        cout << "DIABOLICO" << endl;
      } else {
        cout << "ESOTERICO" << endl;
      }
    } else {
      int sumaLaterales = a[0][n / 2 - 1] + a[0][n / 2] + a[n - 1][n / 2 - 1] + a[n - 1][n / 2] +
                          a[n / 2 - 1][0] + a[n / 2][0] + a[n / 2 - 1][n - 1] + a[n / 2][n - 1];
      int sumaCentro = a[n / 2 - 1][n / 2 - 1] + a[n / 2 - 1][n / 2] + a[n / 2][n / 2 - 1] + a[n / 2][n / 2];
      if (sumaLaterales != 2 * cm2 || sumaCentro != cm2) {
        cout << "DIABOLICO" << endl;
      } else {
        cout << "ESOTERICO" << endl;
      }
    }
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
