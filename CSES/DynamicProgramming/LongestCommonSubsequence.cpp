#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  vector<int> ans;
  int i = n, j = m;
  int curr = dp[n][m];
  while (i > 0 && j > 0) {
    i--;
    if (dp[i][j] != curr) {
      int newI = i;
      i++;

      while (dp[i][j] == curr) {
        j--;
      }

      i = newI;
      ans.push_back(a[i]);

      curr = dp[i][j];
    }
  }

  reverse(ans.begin(), ans.end());

  cout << dp[n][m] << "\n";

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
  }
  cout << "\n";
  return 0;
}
