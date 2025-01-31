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
  ll n, m, k;
  cin >> n >> m >> k;
  string s;
  cin >> s;

  ll leftToUse = 0;
  ll ans = 0;
  vll weakness(s.length());
  REP (i, 0, s.length()) {
    if (leftToUse) {
      leftToUse--;
      weakness[i] = 0;
      continue;
    }
    if (i == 0) {
      weakness[i] = (s[0] == '1' ? 0 : 1);
      if (weakness[i] >= m) {
        weakness[i] = 0;
        leftToUse += (k - 1);
        ans++;
      }
      continue;
    }

    weakness[i] = (s[i] == '1' ? 0 : 1 + weakness[i - 1]);

    if (weakness[i] >= m) {
      weakness[i] = 0;
      leftToUse += (k - 1);
      ans++;
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
