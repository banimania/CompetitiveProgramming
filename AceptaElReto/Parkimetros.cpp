#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, c;
  cin >> n >> c;

  vector<int> coins(n);

  vector<bool> dp(2001, false);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];

    dp[coins[i]] = true;
  }

  vector<bool> newDP(dp.begin(), dp.end());
  for (int i = 1; i < c; i++) {
    for (int j = 0; j < 2001; j++) {
      if (dp[j]) {
        for (int k = 0; k < n; k++) {
          newDP[j + coins[k]] = true;
        }
      }
    }

    dp = newDP;
    newDP = vector<bool>(dp.begin(), dp.end());
  }

  int ans = 0;

  for (int i = 0; i < 2001; i++) {
    ans += dp[i];
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
