#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 10000;

int main() {
  vector<int> dp(MAXN + 1, INT_MAX);
  dp[0] = 0; dp[1] = 0; dp[10] = 0; dp[11] = 0; dp[100] = 0; dp[101] = 0; dp[110] = 0; dp[111] = 0; dp[1000] = 0; dp[1001] = 0; dp[1010] = 0; dp[1011] = 0; dp[1100] = 0; dp[1101] = 0; dp[1110] = 0; dp[1111] = 0; dp[10000] = 0;

  for (int i = 2; i <= MAXN; i++) {
    for (int k = 1; k <= i / 2; k++) {
      dp[i] = min(dp[i], 1 + dp[k] + dp[i - k]);
    }

    int mult = 0;
    for (int k = 2; k * k <= i; k++) {
      if (i % k == 0) {
        int q = i / k;
        int q2 = i / q;
        dp[i] = min(dp[i], dp[q] + dp[q2] + 1);
      }
    }
  }

  int n;
  while (cin >> n && n) {
    cout << dp[n] << '\n';
  }
  return 0;
}
