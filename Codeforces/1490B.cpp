#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

#define TESTCASES true

void solve() {
  ll n;
  cin >> n;
  vll a(n);
  SCAN(a, n);

  ll ans = 0;

  ll target = n / 3;
  ll c0 = 0, c1 = 0, c2 = 0;
  REP (i, 0, n) {
    if (a[i] % 3 == 0) c0++;
    else if (a[i] % 3 == 1) c1++;
    else if (a[i] % 3 == 2) c2++;
  }

  while (c0 != target || c1 != target || c2 != target) {
    if (c0 >= c1 && c0 >= c2) { // c0 max
      ll sobra = c0 - target;
      ans += sobra;
      c1 += sobra;
      c0 -= sobra;
    }
    if (c1 >= c0 && c1 >= c2) { // c1 max
      ll sobra = c1 - target;
      ans += sobra;
      c2 += sobra;
      c1 -= sobra;
    }
    if (c2 >= c0 && c2 >= c1) { // c2 max
      ll sobra = c2 - target;
      ans += sobra;
      c0 += sobra;
      c2 -= sobra;
    }
  }

  cout << ans << endl;
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
