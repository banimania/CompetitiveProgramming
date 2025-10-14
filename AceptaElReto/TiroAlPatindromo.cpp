#include <bits/stdc++.h>
using namespace std;

int longestPalindromicSubsequence(int i, int j, const string &s, vector<vector<pair<int, int>>> &dp) {
  int len = j - i + 1;
  if (i > j) return 0;
  if (dp[i][j].first != -1) return dp[i][j].first;
  if (len == 1) {
    dp[i][j] = {1, 0};
    return dp[i][j].first;
  }

  dp[i][j] = {0, 0};

  if (s[i] == s[j]) {
    dp[i][j] = {2 + longestPalindromicSubsequence(i + 1, j - 1, s, dp), 1};
  }

  int takeFirst = longestPalindromicSubsequence(i + 1, j, s, dp);
  int takeSecond = longestPalindromicSubsequence(i, j - 1, s, dp);
  
  if (takeFirst >= dp[i][j].first) {
    dp[i][j] = {takeFirst, 2};
  }

  if (takeSecond > dp[i][j].first) {
    dp[i][j] = {takeSecond, 3};
  }

  return dp[i][j].first;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  string s;
  while (cin >> s) {
    vector<vector<pair<int, int>>> dp(s.size(), vector<pair<int, int>>(s.size(), {-1, 0}));
    longestPalindromicSubsequence(0, s.size() - 1, s, dp);
    string ans = "";
    stack<char> st;

    int currI = 0;
    int currJ = s.size() - 1;

    while (currI <= currJ) {
      if (currI == currJ) {
        ans += string(1, s[currI]);
        break;
      }
      int curr = dp[currI][currJ].second;
      if (curr == 1) {
        ans += string(1, s[currI]);
        st.push(s[currJ]);
        currI++;
        currJ--;
      } else if (curr == 2) {
        currI++;
      } else if (curr == 3) {
        currJ--;
      }
    }

    while (!st.empty()) {
      ans += string(1, st.top());
      st.pop();
    }
    cout << ans << endl;
  }

  return 0;
}
