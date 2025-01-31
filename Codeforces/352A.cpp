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
  ll n;
  cin >> n;
  vll a(n);
  int cincos = 0;
  int ceros = 0;
  REP (i, 0, n) {
    cin >> a[i];
    if (a[i] == 0) ceros++;
    else if (a[i] == 5) cincos++;
  }

  if (ceros == 0) {
    cout << -1 << endl;
  } else {
    int suma = 0;
    int ncincos = 0;
    REP (i, 1, cincos + 1) {
      suma += 5;
      if (suma % 9 == 0) {
        ncincos = suma / 5;
      }
    }

    if (ncincos == 0) {
      cout << 0 << endl;
      return 0;
    }
    string ans = "";
    REP (i, 0, ncincos) {
      ans += '5';
    }
    REP (i, 0, ceros) {
      ans += '0';
    }

    cout << ans << endl;
  }

}
