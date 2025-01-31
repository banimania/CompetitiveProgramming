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

  vector<vector<char>> a(2, vector<char>(n));
  REP (i, 0, 2) {
    string s;
    cin >> s;

    REP (j, 0, s.length()) {
      a[i][j] = s[j];
    }
  }

  ll ans = 0;
  REP (i, 0, 2) {
    REP (j, 1, n - 1) {
      if (a[i][j] == '.' && a[i][j - 1] == '.' && a[i][j + 1] == '.') {
        if (i == 0) {
          if (a[i + 1][j] == '.' && a[i + 1][j - 1] == 'x' && a[i + 1][j + 1] == 'x') ans++;
        } else {
          if (a[i - 1][j] == '.' && a[i - 1][j - 1] == 'x' && a[i - 1][j + 1] == 'x') ans++;
        }
      }
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
