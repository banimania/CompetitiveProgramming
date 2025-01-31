#include <cctype>
#include <cmath>
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

int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll k;
    cin >> k;

    cout << (ll)(k + floorl(sqrtl(k) + 0.5)) << endl;
  }
  /*vector<ll> a(t);
  REP (i, 0, t) {
    cin >> a[i];
  }

  ll max = a[MAX(a)];
  vll sum(2 * max, 0);
  REP (i, 1, sum.size()) {
    sum[i] = sum[i - 1] + (sqrt(i) == (int) sqrt(i) ? 0 : 1);
  }

  REP (i, 0, t) {
    cout << LOWER(sum, a[i]) << endl;
  }*/
  return 0;
}
