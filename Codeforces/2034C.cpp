/*
▗▄▄▄  ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖ ▗▄▖ 
▐▌  █▐▌ ▐▌▐▛▚▖▐▌  █  ▐▛▚▞▜▌▐▌ ▐▌▐▛▚▖▐▌  █  ▐▌ ▐▌
▐▌  █▐▛▀▜▌▐▌ ▝▜▌  █  ▐▌  ▐▌▐▛▀▜▌▐▌ ▝▜▌  █  ▐▛▀▜▌
▐▙▄▄▀▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌ ▐▌
*/

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

void dfs(vector<vector<char>> &a, set<pair<ll, ll>> &exits, pair<ll, ll> &salida) {
  stack<pair<ll, ll>> pila;
  set<pair<ll, ll>> visitado;
  pila.push(salida);

  while (!pila.empty()) {
    pair<ll, ll> actual = pila.top();
    ll i = actual.first;
    ll j = actual.second;

    if (visitado.count({i, j})) {
      pila.pop();
      continue;
    }
    
    exits.insert(actual);
    visitado.insert(actual);

    if (i != 0 && a[i - 1][j] == 'D' && !exits.count({i - 1, j})) pila.push({i - 1, j});
    if (i != a.size() - 1 && a[i + 1][j] == 'U' && !exits.count({i + 1, j})) pila.push({i + 1, j});
    if (j != 0 && a[i][j - 1] == 'R' && !exits.count({i, j - 1})) pila.push({i, j - 1});
    if (j != a[0].size() - 1 && a[i][j + 1] == 'L' && !exits.count({i, j + 1})) pila.push({i, j + 1});
  }
}

void solve() {
  ll n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));

  set<pair<ll, ll>> exits;
  set<pair<ll, ll>> qms;

  REP (i, 0, n) {
    REP (j, 0, m) {
      cin >> a[i][j];

      if (i == 0 && a[i][j] == 'U') exits.insert({i, j});
      else if (i == n - 1 && a[i][j] == 'D') exits.insert({i, j});
      else if (j == 0 && a[i][j] == 'L') exits.insert({i, j});
      else if (j == m - 1 && a[i][j] == 'R') exits.insert({i, j});
      
      if (a[i][j] == '?') qms.insert({i, j});
    }
  }

  for (pair<ll, ll> exit : exits) {
    dfs(a, exits, exit);
  }

  for (pair<ll, ll> qm : qms) {
    ll i = qm.first;
    ll j = qm.second;

    if ((i == 0 || exits.count({i - 1, j}))
      && (i == a.size() - 1 || exits.count({i + 1, j}))
      && (j == 0 || exits.count({i, j - 1}))
      && (j == a[0].size() - 1 || exits.count({i, j + 1}))) exits.insert({i, j});

  }
  cout << n * m - exits.size() << endl;
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
