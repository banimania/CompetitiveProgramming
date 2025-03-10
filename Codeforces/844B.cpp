#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> board(n, vector<ll>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll b = 0, w = 0;
    for (int j = 0; j < m; j++) {
      if (board[i][j]) b++;
      else w++;
    }
    sum += (1 << b) + (1 << w) - 2;
  }

  for (int j = 0; j < m; j++) {
    ll b = 0, w = 0;
    for (int i = 0; i < n; i++) {
      if (board[i][j]) b++;
      else w++;
    }
    sum += (1 << b) + (1 << w) - 2;
  }

  ll ans = sum - (n * m);

  cout << ans << endl;
}

int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
