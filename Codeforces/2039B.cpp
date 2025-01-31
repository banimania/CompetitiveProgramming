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

/*int numSubstrings(string s) {
  if (s.length() == 1) return 1;
  map<char, int> letters;
  REP (i, 0, s.length()) {
    if (!letters.count(s[i])) letters[s[i]] = 1;
    else letters[s[i]]++;
  }

  ll d = 0;

  for (pair<char, int> par : letters) {
    if (par.second > 1) d++;
  }

  if (d > 0) d++;

  return (s.length() * (s.length() + 1)) / 2  - d;
}*/

void solve() {
  string s;
  cin >> s;

  REP (i, 0, s.length() - 1) {
    if (s[i] == s[i + 1]) {
      cout << s[i] << s[i + 1] << endl;
      return;
    }
  }

  REP (i, 1, s.length() - 1) {
    if (s[i] != s[i - 1] && s[i - 1] != s[i + 1] && s[i] != s[i - 1]) {
      cout << s[i - 1] << s[i] << s[i + 1] << endl;
      return;
    }
  }

  cout << -1 << endl;
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
