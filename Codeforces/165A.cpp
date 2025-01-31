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

int main() {
  int n;
  cin >> n;

  vector<int> x(n), y(n);
  REP (i, 0, n) {
    cin >> x[i] >> y[i];
  }

  int num = 0;

  REP (i, 0, n) {
    bool ln = false, rn = false, un = false, dn = false;
    REP (j, 0, n) {
      if (i == j) continue;
      if (x[i] == x[j]) {
        if (y[i] > y[j]) dn = true;
        else un = true;
      } else if (y[i] == y[j]) {
        if (x[i] > x[j]) ln = true;
        else rn = true;
      }
      if (ln && rn && un && dn) {
        num++;
        break;
      }
    }
  }

  cout << num << endl;
}
