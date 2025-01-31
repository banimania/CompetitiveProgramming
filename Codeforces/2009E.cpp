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

ll calcMin(ll mid, ll n, ll k) {
  ll midN = mid + k;
  ll totalSum = ((n + k) * (n + k - 1)) / 2 - (k * (k - 1)) / 2;
  ll sum = (midN * (midN + 1)) / 2 - (k * (k - 1)) / 2;
  ll sub = totalSum - sum;
  return abs(sum - sub);
}

void solve() {
  ll n, k;
  cin >> n >> k;

  ll min = LLONG_MAX;

  ll bajo = 0;
  ll alto = n;

  while (alto >= bajo) {
    ll medio = (alto + bajo) / 2;
    ll diff = calcMin(medio, n, k);

    min = fmin(diff, min);

    if (calcMin(medio - 1, n, k) < diff) {
      alto = medio - 1;
    } else {
      bajo = medio + 1;
    }
  }

  cout << min << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
