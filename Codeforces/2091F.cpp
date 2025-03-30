#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 998244353;

double dist(int i1, int j1, int i2, int j2) {
  return sqrt(pow(i1 - i2, 2) + pow(j1 - j2, 2));
}

void solve() {
  ll n, m, d;
  cin >> n >> m >> d;

  vector<vector<char>> a(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(2)));
  for (int j = 0; j < m; j++) {
    if (a[n - 1][j] == 'X') dp[n - 1][j][0] = 1;
  }

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        if (a[i][j] == '#' || !dp[i][j][k]) continue;
        if (k == 0) {
          for (int x = max(0LL, j - d); x < min(m, j + d + 1); x++) {
            if (x == j || a[i][x] == '#') continue;
            dp[i][x][1] = (dp[i][x][1] + dp[i][j][k]) % MOD;
          }
        }
      }
    }
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        if (i != 0) {
          for (int x = max(0LL, j - d); x < min(m, j + d + 1); x++) {
            if (a[i - 1][x] == '#' || dist(i, j, i - 1, x) > d) continue;
            dp[i - 1][x][0] = (dp[i - 1][x][0] + dp[i][j][k]) % MOD;
          }
        }
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j < m; j++) {
    ans = (ans + (dp[0][j][0] % MOD) + (dp[0][j][1] % MOD)) % MOD;
  }

  cout << ans << endl;
}

int main() {
  ll t;
  cin >> t;

  while (t--) solve();

  return 0;
}
