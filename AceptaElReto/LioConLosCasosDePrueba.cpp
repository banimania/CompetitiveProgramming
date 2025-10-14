#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<bool> dp(n + 1);
    dp[n] = true;

    int ans = n;
    for (int i = n - 1; i > 0; i--) {
      if (i + a[i] + 1 <= n && dp[i + a[i] + 1]) dp[i] = true;
      if (dp[i]) ans = i;
    }
    cout << ans << endl;
  }
  return 0;
}
