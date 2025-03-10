#include <bits/stdc++.h>
using namespace std;

int maxComida(int i, int j, vector<int> &a, vector<vector<int>> &dp) {
  if (dp[i][j] != INT_MAX) return dp[i][j];

  if (i == j) return dp[i][j] = a[i];

  int comerI = a[i];
  int comerJ = a[j];

  if (j - i > 1) {
    if (a[i + 1] > a[j]) {
      comerI += maxComida(i + 2, j, a, dp);
    } else {
      comerI += maxComida(i + 1, j - 1, a, dp);
    }

    if (a[i] > a[j - 1]) {
      comerJ += maxComida(i + 1, j - 1, a, dp);
    } else {
      comerJ += maxComida(i, j - 2, a, dp);
    }
  }

  return dp[i][j] = max(
    comerI,
    comerJ
  );
}

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    cout << maxComida(0, n - 1, a, dp) << endl;
  }
  return 0;
}
