#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

const ll MOD = 1e9 + 7;

#define TESTCASES false

set<pair<string, pair<ll, ll>>> moves = {
  {"L", {0, -1}},
  {"R", {0, 1}},
  {"U", {1, 0}},
  {"D", {-1, 0}},
  {"LU", {1, -1}},
  {"LD", {-1, -1}},
  {"RU", {1, -1}},
  {"RD", {-1, 1}},
};
void solve() {
  string sc, tc;
  cin >> sc >> tc;

  ll xs = sc[0] - 'a';
  ll ys = 7 - (sc[1] - '0' - 1);

  ll xt = tc[0] - 'a';
  ll yt = 7 - (tc[1] - '0' - 1);
  vector<string> ans;
  while (pair<ll, ll>{ys, xs} != pair<ll, ll>{yt, xt}) {
    ll deltaY = yt - ys;
    ll deltaX = xt - xs;

    if (deltaY > 0 && deltaX > 0) {
      ans.push_back("RD");
      xs++;
      ys++;
    } else if (deltaY < 0 && deltaX > 0) {
      ans.push_back("RU");
      xs++;
      ys--;
    } else if (deltaY > 0 && deltaX < 0) {
      ans.push_back("LD");
      xs--;
      ys++;
    } else if (deltaY < 0 && deltaX < 0) {
      ans.push_back("LU");
      xs--;
      ys--;
    } else if (deltaY > 0 && deltaX == 0) {
      ans.push_back("D");
      ys++;
    } else if (deltaY < 0 && deltaX == 0) {
      ans.push_back("U");
      ys--;
    } else if (deltaY == 0 && deltaX > 0) {
      ans.push_back("R");
      xs++;
    } else if (deltaY == 0 && deltaX < 0) {
      ans.push_back("L");
      xs--;
    }
  }

  cout << ans.size() << endl;
  REP (i, 0, ans.size()) {
    cout << ans[i] << endl;
  }
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
