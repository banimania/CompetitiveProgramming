#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  vector<vector<int>> dp(2001);
  dp[0] = {1};
  for (int i = 1; i < dp.size(); i++) {
    dp[i] = vector<int>(i + 1);

    dp[i][0] = dp[i - 1][0] + i;
    for (int j = 1; j < dp[i].size(); j++) {
      dp[i][j] = dp[i][j - 1] + 1;
    }
  }

  while (t--) {
    int n, m;
    cin >> n >> m;

    int f = 1 + (n + m) / 2 + ((n + m) * (n + m)) / 2;
    cout << dp[n + m][abs(n - m)] << endl;
  }
  return 0;
}
