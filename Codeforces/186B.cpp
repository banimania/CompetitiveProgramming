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
  ll n, t1, t2, k;
  cin >> n >> t1 >> t2 >> k;

  vll a(n), b(n);
  vector<pair<ll, double>> res;
  REP (i, 0, n) {
    cin >> a[i] >> b[i];
    
    double ans = max((t1 * a[i]) * (1 - k / 100.0f) + (t2 * b[i]), (t1 * b[i]) * (1 - k / 100.0f) + (t2 * a[i]));

    res.push_back({i + 1, ans});
  }

  sort(res.begin(), res.end(), [](const pair<ll, double> &a, const pair<ll, double> &b) {
    if (abs(a.second - b.second) < 0.01) return a.first < b.first;
    return a.second > b.second;
  });

  REP (i, 0, n) {
    pair<ll, double> par = res[i];

    cout << par.first << " " << fixed << setprecision(2) << par.second << endl;
  }

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
