#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  while (cin >> n >> k) {
    vector<int> d(n), b(n), dp(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    dp[0] = b[0];

    for (int i = 1; i < n; i++) {
      dp[i] = dp[i - 1];

      int j = upper_bound(d.begin(), d.begin() + i, d[i] - k) - d.begin() - 1;
      if (j >= 0 && d[i] - d[j] >= k) {
        dp[i] = max(dp[i], dp[j] + b[i]);
      }

      dp[i] = max(dp[i], b[i]);
    }
    
    cout << dp[n - 1] << endl;
  }
  return 0;
}
