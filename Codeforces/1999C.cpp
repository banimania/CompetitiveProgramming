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
  ll n, s, m;
  cin >> n >> s >> m;
  vector<ll> l(n), r(n);
  REP (i, 0, n) {
    cin >> l[i] >> r[i];
  }

  if (l[0] >= s || m - r[n - 1] >= s) {
    cout << "YES" << endl;
    return;
  }

  REP (i, 0, n - 1) {
    if (l[i + 1] - r[i] >= s) {
      cout << "YES" << endl;
      return;
    }
  }

  cout << "NO" << endl;
}

int main(){
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
