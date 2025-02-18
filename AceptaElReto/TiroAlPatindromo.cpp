#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(int i, int j, string &s, vector<vector<string>> &dp) {
  if (i > j) return "";
  if (!dp[i][j].empty()) return dp[i][j];

  string bestPal = "";
  if (i == j) return string(1, s[i]);
  if (s[i] == s[j]) bestPal = s[i] + longestPalindrome(i + 1, j - 1, s, dp) + s[j];

  if (s[i] != s[j]) {
    string takeI = longestPalindrome(i + 1, j, s, dp);
    string takeJ = longestPalindrome(i, j - 1, s, dp);
    bestPal = (takeI.length() >= takeJ.length() ? takeI : takeJ);
  }

  return dp[i][j] = bestPal;
}

int main() {
  string s;
  while (cin >> s) {
    vector<vector<string>> dp(s.size(), vector<string>(s.size(), ""));

    cout << longestPalindrome(0, s.size() - 1, s, dp) << endl;
  }

  return 0;
}
