#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  vll b(n), c(m);
  REP (i, 0, n) cin >> b[i];
  REP (i, 0, m) cin >> c[i];

  int ans = 0;
  REP (i, 0, n) {
    REP (j, 0, m) {
      if (b[i] + c[j] <= k) ans++;
    }
  }

  cout << ans << endl;
}

int main() {
  ll t;
  cin >> t;

  while (t--) {
    solve();
  }
}
