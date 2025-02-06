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

#define TESTCASES true

void solve() {
  string n;
  cin >> n;

  if (n.length() < 4) n.insert(n.begin(), 4 - n.length(), '0');
  bool repDigit = true;
  REP (i, 1, n.size()) {
    if (n[i] != n[0]) {
      repDigit = false;
      break;
    }
  }

  if (repDigit) {
    cout << "8" << endl;
    return;
  }

  ll cnt = 0;
  while (n != "6174") {
    sort(n.begin(), n.end());
    string n1 = n;
    string n2 = n;
    reverse(n2.begin(), n2.end());

    ll a = stoll(n1);
    ll b = stoll(n2);

    cnt++;
    n = to_string(b - a);
    
    if (n.length() < 4) n.insert(n.begin(), 4 - n.length(), '0');
  }
  cout << cnt << endl;
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
