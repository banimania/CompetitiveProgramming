#include <bits/stdc++.h>
using namespace std;

int minTrims(int i, int j, string &s, vector<vector<int>> &dp) {
  if (i > j) return 0;
  if (dp[i][j] != INT_MAX) return dp[i][j];

  int newI = i, newJ = j;
  while (newI <= j && s[i] == s[newI]) {
    newI++;
  }

  while (newJ >= i && s[j] == s[newJ]) {
    newJ--;
  }

  if (s[i] == s[j]) {
    dp[i][j] = 1 + minTrims(newI, newJ, s, dp);
  } else {
    dp[i][j] = min(1 + minTrims(newI, j, s, dp), 1 + minTrims(i, newJ, s, dp));
  }

  return dp[i][j];
}

int main() {
  string s;
  while (cin >> s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), INT_MAX));

    cout << minTrims(0, s.size() - 1, s, dp) << endl;
  }
  return 0;
}
