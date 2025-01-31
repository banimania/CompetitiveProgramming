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
  
  /*vll a(n);
  SCAN(a, n);

  vll f(n), g(n);
  vll prefixF(n), prefixG(n);

  REP (i, 0, n) {
    f[i] = (a[i] >= k ? a[i] : 0);
    g[i] = (a[i] <= m ? a[i] : 0);
    prefixF[i] = (i == 0 ? f[i] : f[i] + prefixF[i - 1]);
    prefixG[i] = (i == 0 ? g[i] : g[i] + prefixG[i - 1]);
    //cout << "f[" << i << "] = " << f[i] << " g[" << i << "] = " << g[i] << endl;
    //cout << "prefixF[" << i << "] = " << prefixF[i] << " prefixG[" << i << "] = " << prefixG[i] << endl;
  }
  ll sumF = 0, sumG = 0;
  REP (i, 0, n) {
    sumF += prefixF[i];
    sumG += prefixG[i];
  }
  ll max = sumF - sumG;
  cout << max << endl;*/

  for (ll i = n; i > m; i--) {
    cout << i << " ";
  }
  for (ll i = 1; i <= m; i++) {
    cout << i << " ";
  }
  cout << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
