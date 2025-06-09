#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l;
  cin >> n >> l;

  vector<pair<int, int>> formulas(n);
  for (int i = 0; i < n; i++) {
    cin >> formulas[i].first >> formulas[i].second;
  }

  int bestJ = 0;
  vector<vector<int>> dp(n, vector<int>(l + 1));
  vector<vector<int>> prev(n, vector<int>(l + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= l; j++) {
      int skip = (i > 0 ? dp[i - 1][j] : 0);
      int take = (j >= formulas[i].first ? formulas[i].second + (i > 0 ? dp[i - 1][j - formulas[i].first] : 0) : INT_MIN);

      if (i > 0) {
        if (take >= skip) {
          prev[i][j] = j - formulas[i].first;
        } else {
          prev[i][j] = j;
        }
      }
      dp[i][j] = max(skip, take);
    }
  }

  for (int j = 1; j <= l; j++) {
    if (dp[n - 1][j] > dp[n - 1][bestJ]) {
      bestJ = j;
    }
  }

  int currI = n - 1;
  int currJ = bestJ;

  vector<int> ans;
  int num = 0;
  while (currI >= 0) {
    int newJ = prev[currI][currJ];

    if (newJ != currJ) {
      ans.push_back(currI);
      num++;
    }

    currI--;
    currJ = newJ;
  }

  reverse(ans.begin(), ans.end());

  cout << num << " " << dp[n - 1][bestJ] << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
