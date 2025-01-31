/*
▗▄▄▄  ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖ ▗▄▖ 
▐▌  █▐▌ ▐▌▐▛▚▖▐▌  █  ▐▛▚▞▜▌▐▌ ▐▌▐▛▚▖▐▌  █  ▐▌ ▐▌
▐▌  █▐▛▀▜▌▐▌ ▝▜▌  █  ▐▌  ▐▌▐▛▀▜▌▐▌ ▝▜▌  █  ▐▛▀▜▌
▐▙▄▄▀▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌ ▐▌
*/

#include <algorithm>
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

  SORTDESC(a);

  ll sum = 0;
  vll prefixSum(n);
  REP (i, 0, a.size()) {
    sum += a[i];
    prefixSum[i] = sum;
  }

  ll index = LOWER(prefixSum, k);

  if (prefixSum[index] == k) {
    cout << 0 << endl;
    return;
  } else {
    cout << abs((prefixSum[index - 1]) - k) << endl;
    return;
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
