#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  vector<ll> dp(10001, 0);

  for (int i = 1; i <= 10; i++) dp[i] = 1;

  for (int i = 1; i <= 10000; i++) {
    for (int j = 1; j <= 10; j++) {
      if (i - j - 1 > 0) {
        dp[i] = (dp[i] + dp[i - j - 1]) % MOD;
      }
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    cout << dp[n] << '\n';
  }
  return 0;
}
