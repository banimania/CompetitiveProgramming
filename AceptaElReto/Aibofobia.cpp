#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(int i, int j, string &s, vector<vector<int>> &dp) {
  if (i > j) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int bestPal = 0;
  if (i == j) return 1;
  if (s[i] == s[j]) bestPal = longestPalindrome(i + 1, j - 1, s, dp) + 2;

  if (s[i] != s[j]) {
    int takeI = longestPalindrome(i + 1, j, s, dp);
    int takeJ = longestPalindrome(i, j - 1, s, dp);
    bestPal = max(takeI, takeJ);
  }

  return dp[i][j] = bestPal;
}

int main() {
  string s;
  while (cin >> s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));

    cout << s.size() - longestPalindrome(0, s.size() - 1, s, dp) << endl;

  }
  return 0;
}
