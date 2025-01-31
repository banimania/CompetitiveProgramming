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

int main() {
  int lights[3][3];
  int switches[3][3];
  REP (i, 0, 3) {
    REP (j, 0, 3) {
      cin >> switches[i][j];
      lights[i][j] = 1;
    }
  }

  REP (i, 0, 3) {
    REP (j, 0, 3) {
      if (switches[i][j] % 2 != 0) {
        if (i > 0) lights[i - 1][j] = !lights[i - 1][j];
        if (i < 2) lights[i + 1][j] = !lights[i + 1][j];
        if (j > 0) lights[i][j - 1] = !lights[i][j - 1];
        if (j < 2) lights[i][j + 1] = !lights[i][j + 1];
        lights[i][j] = !lights[i][j];
      }
    }
  }

  REP (i, 0, 3) {
    REP (j, 0, 3) {
      cout << lights[i][j];
    }
    cout << endl;
  }
  return 0;
}
