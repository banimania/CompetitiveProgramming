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
  int n;
  while (cin >> n && n) {
    vector<int> cpasInicio;
    vector<int> cpasFinal;
    REP (i, 0, n) {
      int cInicio, cFin;
      cin >> cInicio >> cFin;
      cpasInicio.push_back(cInicio);
      cpasFinal.push_back(cFin);
    }

    int cnt = 0;
    int p = 0;
    int mart;
    while (cin >> mart && mart) {
      cnt++;
      int index = upper_bound(cpasInicio.begin(), cpasInicio.end(), mart) - cpasInicio.begin();
      if (cpasInicio[index - 1] <= mart && cpasFinal[index - 1] >= mart) {
        p--;
      }
    }

    cout << cnt + p << endl;
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
