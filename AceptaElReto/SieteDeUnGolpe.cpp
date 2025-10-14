#include <bits/stdc++.h>
using namespace std;

int sum(int i, int j, int i2, int j2, vector<vector<int>> &pSum) {
  return pSum[i2][j2] - pSum[i2][j - 1] - pSum[i - 1][j2] + pSum[i - 1][j - 1];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n, m, mi, mj;
  while (cin >> m >> n >> mj >> mi) {
    if (!n && !m && !mi && !mj) break;

    vector<vector<int>> pSum(n + 1, vector<int>(m + 1));
    vector<int> ans(8, 0);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        char x;
        cin >> x;

        pSum[i][j] = (x == 'X') + pSum[i - 1][j] + pSum[i][j - 1] - pSum[i - 1][j - 1];
      }
    }

    for (int i = 1; i <= n - mi + 1; i++) {
      for (int j = 1; j <= m - mj + 1; j++) {
        int i2 = i + mi - 1;
        int j2 = j + mj - 1;

        int s = sum(i, j, i2, j2, pSum);

        if (s <= 7) ans[s]++;
      }
    }

    for (int i = 0; i <= 7; i++) {
      cout << ans[i] << (i == 7 ? "" : " ");
    }
    cout << endl;
  }
  return 0;
}
