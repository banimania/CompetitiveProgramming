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

// ll getMinBills(ll n, map<ll, ll> &dp, vll &bills) {
//   if (dp.count(n)) return dp[n];

//   ll ans = INT_MAX;

//   REP (i, 0, bills.size()) {
//     ll newAmount = n - bills[i];
//     if (newAmount >= 0) {
//       ans = min(ans, getMinBills(newAmount, dp, bills) + 1);
//     }
//   }

//   return dp[n] = ans;
// }

// void solve() {
//   ll n;
//   cin >> n;
//   
//   vll bills = {1, 5, 10, 20, 100};
//   map<ll, ll> dp;
//   dp[0] = 0;
//   REP (i, 0, bills.size()) {
//     dp[bills[i]] = 1;
//   }

//   cout << getMinBills(n, dp, bills) << endl;
// }

void solve() {
  ll n;
  cin >> n;

  ll amount100 = n / 100;
  ll amount20 = (n % 100) / 20;
  ll amount10 = (n % 20) / 10;
  ll amount5 = (n % 10) / 5;
  ll amount1 = n % 5;

  cout << amount100 + amount20 + amount10 + amount5 + amount1 << endl;
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
