#include <cctype>
#include <iostream>
#include <algorithm>
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
#define MOD 1e9 + 7

int countMoves(const vector<vector<ll>>& a, int target, int d) {
  int moves = 0;

  REP (i, 0, a.size()) {
    REP (j, 0, a[i].size()) {
      if (a[i][j] != target) {
        ll dif = abs(a[i][j] - target);
        if (dif % d != 0) {
          return -1;
        }
        moves += dif / d;
      }
    }
  }
  return moves;
}

int main() {
  ll n, m, d;
  cin >> n >> m >> d;
  vector<vector<ll>> a(n);
  vector<ll> xd;

  ll sum = 0;
  REP (i, 0, n) {
    vector<ll> row(m);
    REP (j, 0, m) {
      cin >> row[j];
      xd.push_back(row[j]);
    }
    a[i] = row;
  }

  /*REP (i, 0, n * m) {
    REP (j, 0, n * m) {
      if (abs(a[(i / n) % n][i % m] - a[(j / n) % n][j % m]) % d != 0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }*/

  SORTASC(xd);
  ll target = xd[(n * m) / 2];
  /*int minMoves = 1e9;
  REP (i, 0, n) {
    REP (j, 0, m) {
      minMoves = min(minMoves, countMoves(a, a[i][j], d));
    }
  }*/

  cout << countMoves(a, target, d) << endl;
}
