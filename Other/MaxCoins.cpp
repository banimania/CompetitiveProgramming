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

#define TESTCASES true

ll maxCoins(ll n, vll &monedas, map<ll, ll> &dp) {
  if (dp.count(n)) return dp[n];

  ll maxMonedas = -1;
  REP (i, 0, monedas.size()) {
    ll moneda = monedas[i];
    if (n - moneda >= 0) {
      maxMonedas = max(maxMonedas, maxCoins(n - moneda, monedas, dp) + 1);
    }
  }

  return dp[n] = maxMonedas;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vll monedas(n);
  SCAN(monedas);
  map<ll, ll> dp;
  dp[0] = 0;

  cout << "Cantidad: " << m << endl << "Monedas: ";
  PRINTLN(monedas);
  cout << maxCoins(m, monedas, dp) << endl;
}

int main() {
  auto start = chrono::high_resolution_clock::now();
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

  cout << "Time: " << duration.count() << " µs" << endl;
  return 0;
}
