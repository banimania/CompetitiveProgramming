#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 7;
  vector<int> a1 = {2, 2, 1};
  vector<int> a2 = {3, 2, 1};
  int n = a1.size();

  vector<vector<bool>> dp(a + 1, vector<bool>(n + 1, false));

  dp[0][0] = true;

  for (int j = 1; j <= n; j++) {
    for (int i = a; i >= 0; i--) {
      if (dp[i][j - 1]) {
        dp[i][j] = true;
        if (i + a1[j - 1] <= a) dp[i + a1[j - 1]][j] = true;
        if (i + a2[j - 1] <= a) dp[i + a2[j - 1]][j] = true;
      }
    }
  }

  for (int i = a; i >= 0; i--) {
    if (dp[i][n]) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
