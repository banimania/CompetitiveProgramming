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
#define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
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
  ll n, a, b;
  cin >> n >> a >> b;

  string s;
  cin >> s;

  int x = 0;
  int y = 0;
  int cnt = 0;
  while (cnt <= 20) {
    cnt++;

    REP (i, 0, s.length()) {
      if (x == a && y == b) {
        cout << "YES" << endl;
        return;
      }
      if (s[i] == 'E') x++;
      else if (s[i] == 'W') x--;
      else if (s[i] == 'N') y++;
      else if (s[i] == 'S') y--;
    }
  }

  cout << "NO" << endl;

}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}

