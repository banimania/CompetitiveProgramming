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

ll gcd(ll a, ll b) {
  while (b != 0) {
    ll temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

void solve() {
  ll num;
  ll total = 0;
  ll mesaSize = 0;
  while (cin >> num) {
    if (num == 0) {
      if (total == 0) return;
      if (total != 0 && mesaSize != 0) {
        cout << total / mesaSize << endl;
        total = 0;
        mesaSize = 0;
      }
    } else {
      if (total == 0) mesaSize = num;
      total += num;
      mesaSize = gcd(mesaSize, total);
    }
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
