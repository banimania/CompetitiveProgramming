#include <cctype>
#include <iostream>
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

int main() {
  ll n, m;
  cin >> n >> m;
  vector<string> board(n);
  vector<pair<int, int>> bad;
  REP (i, 0, n) {
    string s;
    cin >> s;
    board[i] = s;

    REP (j, 0, m) {
      if (board[i][j] == '-') bad.push_back(make_pair(i, j));
    }
  }
  REP (i, 0, n) {
    REP (j, 0, m) {
      char p = 'B';

      if (i > 0 && board[i - 1][j] == 'B') p = 'W';
      else if (j > 0 && board[i][j - 1] == 'B') p = 'W';
      else if (i < n - 1 && board[i + 1][j] == 'B') p = 'W';
      else if (j < m - 1 && board[i][j + 1] == 'B') p = 'W';
      board[i][j] = p;
    }
  }

  for (pair<int, int> p : bad) {
    board[p.first][p.second] = '-';
  }

  REP (i, 0, n) {
    REP (j, 0, m) {
      cout << board[i][j];
    }
    cout << endl;
  }
}
