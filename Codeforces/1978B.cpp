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

ll profitForK(ll n, ll a, ll b, ll k) {
  ll ans = 0;
  
  // REP (i, 1, k + 1) {
  //   ans += (b - i + 1);
  // }

  ll sumaB = (b * (b + 1)) / 2;
  ll sumaPreB = ((b - k) * (b - k + 1)) / 2;

  ans += sumaB - sumaPreB;
  ans += (n - k) * a;

  return ans;
}

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;

  ll maxProfit = 0;

  ll bajo = 0, alto = min(n, b);

  while (alto - bajo >= 3) {
    ll m1 = bajo + (alto - bajo) / 3;
    ll m2 = alto - (alto - bajo) / 3;

    ll prof1 = profitForK(n, a, b, m1);
    ll prof2 = profitForK(n, a, b, m2);
    maxProfit = max({maxProfit, prof1, prof2});

    if (prof1 > prof2) alto = m2;
    else bajo = m1;
  }

  REP (i, bajo, alto + 1) {
    maxProfit = max(maxProfit, profitForK(n, a, b, i));
  }

  cout << maxProfit << endl;
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
