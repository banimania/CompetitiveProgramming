#include <bits/stdc++.h>
using namespace std;

int solve(int i, int ma, int mi, int tu, int td, bool ld, vector<vector<vector<vector<vector<vector<int>>>>>> &dp, const string &l, const string &r, string &ans, string &curr, int &best) {
  if (i == r.size()) {
    if (ma - mi < best) {
      ans = curr;
      best = ma - mi;
    }
    return ma - mi;
  }
  if (dp[i][ma][mi][tu][td][ld] != INT_MAX) return dp[i][ma][mi][tu][td][ld];

  char start = td ? l[i] : '0';
  char end = tu ? r[i] : '9';

  for (char x = start; x <= end; x++) {
    curr[i] = x;
    dp[i][ma][mi][tu][td][ld] = min(dp[i][ma][mi][tu][td][ld], solve(i + 1, (ld && (x == '0')) ? ma : max(ma, x - '0'), (ld && (x == '0')) ? mi : min(mi, x - '0'), tu && x == r[i], td && x == l[i], ld && (x == '0'), dp, l, r, ans, curr, best));
  }

  return dp[i][ma][mi][tu][td][ld];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string l, r;
    cin >> l >> r;

    while (l.size() < r.size()) {
      l.insert(l.begin(), '0');
    }

    vector<vector<vector<vector<vector<vector<int>>>>>> dp(r.size() + 1, vector<vector<vector<vector<vector<int>>>>>(10, vector<vector<vector<vector<int>>>>(10, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, INT_MAX))))));
    string ans = "";
    string curr = l;
    int best = 10;

    solve(0, 0, 9, 1, 1, 1, dp, l, r, ans, curr, best);
    cout << stoll(ans) << endl;
  }
  return 0;
}
