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

void solve() {
  ll n;
  cin >> n;
  string enemies;
  cin >> enemies;
  string pawns;
  cin >> pawns;

  int ourPawns = 0;
  REP (i, 0, pawns.size()) {
    if (pawns[i] == '1') ourPawns++;
  }

  if (ourPawns == 0) {
    cout << 0 << endl;
    return;
  }

  int res = 0;
  REP (i, 0, pawns.size()) {
    if (pawns[i] == '1' && enemies[i] == '0') res++, enemies[i] = '2';
    else if (pawns[i] == '1' && i > 0 && enemies[i - 1] == '1') res++, enemies[i - 1] = '2';
    else if (pawns[i] == '1' && i < n - 1 && enemies[i + 1] == '1') res++, enemies[i + 1] = '2';
  }
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
