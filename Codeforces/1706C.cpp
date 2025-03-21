#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> cost(n - 2);
  for (ll i = 1; i < n - 1; i++) {
    cost[i - 1] = max(max(a[i - 1] - a[i] + 1, 0LL), max(a[i + 1] - a[i] + 1, 0LL));
  }

  if (n % 2) {
    ll ans = 0;

    for (ll i = 0; i < n - 2; i += 2) ans += cost[i];

    cout << ans << endl;
    return;
  }

  vector<vector<ll>> dp(n - 2, vector<ll>(2));

  for (ll i = 0; i < n - 2; i++) {
    for (ll j = 0; j < 2; j++) {
      // . X . X
      dp[i][j] = cost[i] + (i - 2 >= 0 ? dp[i - 2][j] : 0);

      // X . . X
      if (i - 3 >= 0 && j == 1) {
        dp[i][j] = min(dp[i][j], cost[i] + dp[i - 3][0]);
      }
      
      // . X
      if (j == 1 && i == 1) {
        dp[i][j] = min(dp[i][j], cost[i]);
      }
    }
  }

  cout << min({dp[n - 3][0], dp[n - 3][1], (n - 4 >= 0 ? dp[n - 4][0] : LLONG_MAX)}) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
