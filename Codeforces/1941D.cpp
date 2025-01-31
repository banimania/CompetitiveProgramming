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
  ll n, m, x;
  cin >> n >> m >> x;
  x--;

  vector<pair<int, char>> throws;
  REP (i, 0, m) {
    pair<int, char> t;
    cin >> t.first >> t.second;

    throws.push_back(t);
  }

  queue<pair<int, int>> q;
  set<pair<int, int>> visited;
  q.push({x, 0});
  visited.insert({x, 0});
  while (!q.empty()) {
    ll actual = q.front().first;
    ll capa = q.front().second;
    if (capa == m) {
      break;
    }
    q.pop();

    pair<int, char> currentThrow = throws[capa];
    if (currentThrow.second == '0' || currentThrow.second == '?') {
      ll newPos = (((actual + currentThrow.first) % n) + n) % n;
      if (!visited.count({newPos, capa + 1})) {
        visited.insert({newPos, capa + 1});
        q.push({newPos, capa + 1});
      }
    }
    if (currentThrow.second == '1' || currentThrow.second == '?') {
      ll newPos = (((actual - currentThrow.first) % n) + n) % n;
      if (!visited.count({newPos, capa + 1})) {
        visited.insert({newPos, capa + 1});
        q.push({newPos, capa + 1});
      }
    }
  }

  set<ll> posibles;
  while (!q.empty()) {
    posibles.insert(q.front().first + 1);
    q.pop();
  }
  cout << posibles.size() << endl;
  for (ll posible : posibles) {
    cout << posible << " ";
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
