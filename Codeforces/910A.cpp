#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 0

int minJumps(int i, int d, string &path, vector<int> &dp) {
  if (dp[i] != -1) return dp[i];

  dp[i] = INT_MAX;

  if (path[i] == '1') {
    for (int j = i - 1; j >= max(0, i - d); j--) {
      if (path[j] == '1' && minJumps(j, d, path, dp) != INT_MAX) dp[i] = min(dp[i], minJumps(j, d, path, dp) + 1);
    }
  }

  return dp[i];
}

void solve(int tt) {
  int n, d;
  string path;
  cin >> n >> d;
  cin >> path;
  vector<int> dp(n, -1);
  dp[0] = 0;

  int ans = minJumps(n - 1, d, path, dp);

  cout << (ans == INT_MAX ? -1 : ans) << endl;
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
