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
  ll k;
  cin >> k;
  vll a(k);
  SCAN(a, k);

  ll size = k - 2;
  ll n, m;


  SORTASC(a);

  unordered_set<ll> existe;
  REP (i, 0, a.size()) {
    existe.insert(a[i]);
  }
  
  
  REP (i, 0, k) {
    //if (a[i] > k - 2) break;
    n = a[i];
    if (size % n != 0) continue;
    m = size / n;
    if (existe.count(m)) break;
    //if (find(a.begin() + i + 1, a.end(), m) != a.end()) break;
  }

  cout << n << " " << m << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
