#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

static const ll MOD = 999999999989;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, c;
  while (cin >> n >> c) {
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= c; ++j) {
        if (i - j >= 0) {
          dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
      }
    }

    cout << dp[n] << '\n';
  }

  return 0;
}
