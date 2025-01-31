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

  vll a(n);
  REP (i, 0, n) {
    cin >> a[i];
    a[i]--;
  }

  bool ans = true;

  vector<bool> seats(n, false);

  seats[a[0]] = true;
  REP (i, 1, n) {
    bool neighboured = false;

    if (a[i] - 1 >= 0 && seats[a[i] - 1]) neighboured = true;
    else if (a[i] + 1 < n && seats[a[i] + 1]) neighboured = true;

    if (!neighboured) {
      ans = false;
      break;
    }
    seats[a[i]] = true;
  }

  cout << (ans ? "YES" : "NO") << endl;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
