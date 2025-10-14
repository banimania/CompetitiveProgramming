#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adj = {
  {1, {2, 3, 4, 7}},
  {2, {1, 3, 5, 8}},
  {3, {1, 2, 6, 9}},
  {4, {1, 5, 6, 7}},
  {5, {2, 4, 6, 8}},
  {6, {3, 4, 5, 9}},
  {7, {1, 4, 8, 9}},
  {8, {2, 5, 7, 9}},
  {9, {3, 6, 7, 8}}
};

int solve(int num, int last, vector<vector<int>> &dp) {
  if (num > 30) return 1;
  if (dp[num][last] != -1) return dp[num][last];
  
  dp[num][last] = 0;

  for (int move : adj[last]) {
    if (move + num < 31) {
      dp[num][last] |= (!solve(num + move, move, dp));
    }
  }

  return dp[num][last];
}

int main() {
  int t;
  cin >> t;

  vector<vector<int>> dp(32, vector<int>(10, -1));

  while (t--) {
    int x, l;
    cin >> x >> l;
    cout << (solve(x, l, dp) ? "GANA" : "PIERDE") << endl;
  }
  return 0;
}
