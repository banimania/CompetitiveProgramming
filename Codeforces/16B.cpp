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

#define TESTCASES false

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> v(m);
  REP (i, 0, m) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end(), [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second > b.second;
  });

  ll ans = 0;

  ll index = 0;
  ll cajasCogidas = 0;
  while (cajasCogidas < n && index < m) {
    ll numCajas = v[index].first;
    ll numCerillasCaja = v[index].second;
    
    ll numCajasCogidas = fmin(numCajas, fmax(0, n - cajasCogidas));

    cajasCogidas += numCajasCogidas;
    ans += (numCerillasCaja * numCajasCogidas);
    index++;
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
