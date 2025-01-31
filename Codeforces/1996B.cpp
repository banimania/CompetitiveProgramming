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
  int n, k;
  cin >> n >> k;

  int h = n / k;

  vector<string> grid = {};
  REP(i, 0, n) {
    string line;
    cin >> line;
    grid.push_back(line);
  }

  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < n; j += k) {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

int main() {
  ll t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
