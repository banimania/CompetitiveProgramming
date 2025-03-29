#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> alturas(n), costes(n);
    for (int i = 0; i < n; i++) cin >> alturas[i];
    for (int i = 0; i < n; i++) cin >> costes[i];

    int m;
    cin >> m;

    vector<int> dp(n, INT_MAX);
    dp[0] = costes[0];

    for (int i = 1; i < n; i++) {
      for (int j = i - 1; j >= -1; j--) {
        if (j == -1) {
          if (alturas[i] <= m) dp[i] = costes[i];
        } else {
          if (alturas[i] - alturas[j] > m) break;

          dp[i] = min(dp[i], dp[j] + costes[i]);
        }
      }
    }

    int ans = INT_MAX;

    for (int i = n - 1; i >= 0; i--) {
      if (alturas[n - 1] - alturas[i] > m) break;

      ans = min(ans, dp[i]);
    }

    cout << ans << endl;
  }
  return 0;
}
