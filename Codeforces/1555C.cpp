#include <bits/stdc++.h>
using namespace std;

void solve() {
  int m;
  cin >> m;
  vector<vector<int>> a(2, vector<int>(m));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  vector<int> pSum1(m), pSum2(m);
  pSum1[0] = a[0][0];
  pSum2[0] = a[1][0];
  for (int i = 1; i < m; i++) {
    pSum1[i] = pSum1[i - 1] + a[0][i];
    pSum2[i] = pSum2[i - 1] + a[1][i];
  }

  int result = INT_MAX;

  for (int j = 0; j < m; j++) {
    int bobCoins = max(pSum1[m - 1] - pSum1[j], (j > 0 ? pSum2[j - 1] : 0));  
    result = min(result, bobCoins);
  }
  cout << result << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
