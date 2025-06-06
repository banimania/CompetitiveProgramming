#include <bits/stdc++.h>
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

#define TESTCASES true
 
void solve() {
  string s;
  cin >> s;

  if (s.length() == 1) {
    cout << s << (char)('a' + (s[0] + 1) % 26) << endl;
    return;
  }
  ll index = 1;
  REP (i, 1, s.length()) {
    if (s[i] == s[i - 1]) {
      index = i;
      break;
    }
  }

  char newChar = 'x';
  REP(i, 0, 26) {
    if (s[index] != i + 'a' && s[index - 1] != i + 'a') {
      newChar = 'a' + i;
      break;
    }
  }
  cout << s.substr(0, index) + newChar + s.substr(index, s.length() - index) << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
