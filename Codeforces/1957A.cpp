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

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  SCAN(a, n);

  SORTASC(a);

  int aux = 1;
  int ans = 0;
  REP (i, 1, n) {
    if (a[i] == a[i - 1]) {
      aux++;
    }
    if (a[i] != a[i - 1] || i == n - 1) {
      ans += aux / 3;
      aux = 1;
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
