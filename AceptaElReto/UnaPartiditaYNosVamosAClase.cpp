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

#define TESTCASES true

void solve() {
  int l, n;
  cin >> l >> n;

  int ans = 0;
  vector<pair<int, int>> clases;

  REP (i, 0, n) {
    int d;
    string s;
    cin >> s >> d;
    int hora = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, 2));

    clases.push_back({hora * 60 + min, d});
  }

  int ultimaClase = 8 * 60;
  REP (i, 0, clases.size()) {
    if (clases[i].first - ultimaClase >= l) {
      ans += clases[i].first - ultimaClase;
    }
    ultimaClase = clases[i].first + clases[i].second;
  }

  if (14 * 60 - ultimaClase >= l) ans += 14 * 60 - ultimaClase;

  cout << ans << endl;
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
