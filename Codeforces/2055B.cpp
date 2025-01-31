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

#define TESTCASES true

void solve() {
  ll n;
  cin >> n;
  vll a(n), b(n);
  SCAN(a);
  SCAN(b);

  ll sumaA = 0, sumaB = 0;
  REP (i, 0, a.size()) {
    sumaA += a[i];
    sumaB += b[i];
  }

  if (sumaA < sumaB) {
    cout << "NO" << endl;
    return;
  }

  vll requerido(n);
  REP (i, 0, n) requerido[i] = a[i] - b[i];

  SORTASC(requerido);

  ll bsearch = LOWER(requerido, 0);

  if (bsearch == 0) {
    cout << "YES" << endl;
    return;
  } else if (bsearch > 1) {
    cout << "NO" << endl;
    return;
  }

  cout << ((requerido[0] + requerido[1] >= 0) ? "YES" : "NO") << endl;
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
