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

set<ll> check(map<ll, set<ll>> &dp, ll n) {
  if (dp.count(n)) return dp[n];

  set<ll> ans;

  if (n % 3 == 0) {
    ll x = (n / 3);
    ll y = 2 * x;

    ans.insert({x, y});
    for (ll z : check(dp, x)) {
      ans.insert(z);
    }
    for (ll z : check(dp, y)) {
      ans.insert(z);
    }
  }

  return dp[n] = ans;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  if (m > n) {
    cout << "NO" << endl;
    return;
  }

  if (m == n) {
    cout << "YES" << endl;
    return;
  }

  map<ll, set<ll>> dp;

  cout << (check(dp, n).count(m) ? "YES" : "NO") << endl;
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
