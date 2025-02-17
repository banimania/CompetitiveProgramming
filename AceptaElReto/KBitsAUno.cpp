#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
  vector<vector<int>> dp(1001);

  dp[0] = {0};
  for (int i = 1; i <= 1000; i++) {
    dp[i] = vector<int>(i + 1);
    dp[i][0] = 1;
    dp[i][i] = 1;
    for (int j = 1; j < i; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
    }
  }

  int a, b;
  while (cin >> a >> b) {
    if (!a && !b) break;

    cout << (b > a ? 0 : dp[a][b]) << endl;
  }

  return 0;
}
