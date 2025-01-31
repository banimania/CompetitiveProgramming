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

#define TESTCASES false

void solve() {
  ll n, m;
  cin >> n >> m;

  vll a(n), b(m);
  SCAN(a, n);
  SCAN(b, m);

  set<ll> conjunto;
  REP (i, 0, n) if (!conjunto.count(a[i])) conjunto.insert(a[i]);

  map<ll, ll> ultimaPos;
  REP (i, 0, n) {
    ultimaPos[a[i]] = i;
  }

  set<ll> ultimasPos;
  for (pair<ll, ll> par : ultimaPos) {
    ultimasPos.insert(par.second);
  }

  vector<ll> sol(n);
  ll x = conjunto.size();
  REP (i, 0, n) {
    sol[i] = x;
    if (ultimasPos.count(i)) x--;
  }

  REP (i, 0, m) {
    cout << sol[b[i] - 1] << endl;
  }
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
