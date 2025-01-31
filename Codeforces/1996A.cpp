#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define PRINT(a, n) for (int i = 0; i < n; ++i) { cout << a[i] << " "; }
#define PRINTLN(a, n) for (int i = 0; i < n; ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a, n) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a, n) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, n, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, n, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, n, target) lower_bound(a.begin(), a.end(), target) - a.begin()

void solve() {
  int n;
  cin >> n;

  int res = n / 4 + (n % 4) / 2;

  cout << res << endl;
}

int main() {
  ll t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
