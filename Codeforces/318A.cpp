#include <cctype>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))
#define MOD 1e9 + 7

int main() {
  ll n, k;
  cin >> n >> k;

  ll ans = 0;
  if (n % 2 == 0) {
    ll imp = n / 2;
    if (k > imp) {
      ans = (k - imp) * 2;
    } else {
      ans = 2 * k - 1;
    }
  } else {
    ll imp = (n / 2) + 1;
    if (k > imp) {
      ans = (k - imp) * 2;
    } else {
      ans = 2 * k - 1;
    }
  }

  cout << ans << endl;
}
