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
  ll n;
  cin >> n;
  vll a(n);
  SCAN(a, n);

  queue<pair<int, int>> cola;
  vector<bool> visitado(n, false);
  vll sol(n);
  cola.push({MAX(a), 0});
  while (!cola.empty()) {
    pair<int, int> actual = cola.front();
    cola.pop();

    sol[actual.first] = actual.second;
    visitado[actual.first] = true;

    ll maxIndex = -1;
    ll max = LLONG_MIN;
    REP (i, actual.first + 1, n) {
      if (visitado[i]) break;
      if (a[i] > max) {
        maxIndex = i;
        max = a[maxIndex];
      }
    }
    if (maxIndex != -1) cola.push({maxIndex, actual.second + 1});
    
    maxIndex = -1;
    max = LLONG_MIN;
    REPV (i, actual.first - 1, 0) {
      if (visitado[i]) break;
      if (a[i] > max) {
        maxIndex = i;
        max = a[maxIndex];
      }
    }
    if (maxIndex != -1) cola.push({maxIndex, actual.second + 1});
  }

  REP (i, 0, n) {
    cout << sol[i] << " ";
  }
  cout << endl;

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
