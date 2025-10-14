#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    int k;
    cin >> k;

    vector<int> steps(k);
    for (int i = 0; i < k; i++) {
      cin >> steps[i];
    }

    vector<ll> dp(n + 1);
    dp[0] = 1;

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j < k; j++) {
        if (i + steps[j] <= n) {
          dp[i + steps[j]] = (dp[i + steps[j]] + dp[i]) % MOD;
        }
      }
    }

    cout << dp[n] << endl;
  }
  return 0;
}
