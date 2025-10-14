#include <bits/stdc++.h>
using namespace std;

int solve(int n, int last, vector<vector<int>> &dp) {
  if (n >= 1000) return 1;
  if (dp[n][last] != -1) return dp[n][last];

  dp[n][last] = false;
  for (int i = 1; i <= 6; i++) {
    if (last + i != 7 && i != last) {
      dp[n][last] |= !(solve(n + i, i, dp));
    }
  }

  return dp[n][last];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  vector<vector<int>> dp(1001, vector<int>(7, -1));
  int t;
  cin >> t;
  while (t--) {
    int n, last;
    cin >> n >> last;
    cout << (solve(n, last, dp) ? "GANA" : "PIERDE") << endl;
  }

}
