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

void solve() {
  ll n, k;
  cin >> n >> k;
  vll a(n);
  SCAN(a);
  k--;

  bool strongest = true;
  ll first = -1;
  REP (i, 0, n) {
    if (i == k) continue;
    
    if (a[i] > a[k]) {
      strongest = false;
      first = i;
      break;
    }
  }

  if (strongest) {
    cout << n - 1 << endl;
    return;
  }

  ll wins1 = 0;
  ll wins2 = 0;

  vll a1(a);
  swap(a1[0], a1[k]);
  REP (i, 1, n) {
    if (a1[0] > a1[i]) wins1++;
    else break;
  }

  if (k > first) {
    vll a2(a);
    swap(a2[first], a2[k]);
    k = first;
    if (k != 0) wins2++;
    REP (i, k + 1, n) {
      if (a2[k] > a2[i]) wins2++;
      else break;
    }
  }

  cout << max(wins1, wins2) << endl;
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
