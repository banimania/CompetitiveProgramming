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
  string s;
  cin >> s;
  int m;
  cin >> m;

  vll suma(s.length());
  REP (i, 0, s.length()) {
    suma[i] = (s[i] == s[i + 1]) + (i == 0 ? 0 : suma[i - 1]);
  }

  vll lq(m), rq(m);
  REP (i, 0, m) {
    cin >> lq[i] >> rq[i];
  }

  REP (q, 0, m) {
    ll l = lq[q] - 1;
    ll r = rq[q] - 1;

    int ans = suma[r - 1] - (l == 0 ? 0 : suma[l - 1]);
    //int ans = suma[r] - (l == 0 ? 0 : suma[l - 1]);
    cout << ans << endl;
  }
  return 0;
}
