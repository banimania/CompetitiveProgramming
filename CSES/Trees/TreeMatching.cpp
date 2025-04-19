// https://cses.fi/problemset/task/1130

#include <bits/stdc++.h>
using namespace std;

int maxMatch(int i, int j, int parent, vector<vector<int>> &adj, vector<vector<int>> &dp) {
  if (dp[i][j] != -1) return dp[i][j];

  dp[i][j] = 0;

  int notMatch = 0;
  for (int neighbour : adj[i]) {
    if (neighbour == parent) continue;
    
    notMatch += maxMatch(neighbour, 0, i, adj, dp);
  }

  if (j == 0) {
    for (int neighbour : adj[i]) {
      if (neighbour == parent) continue;

      dp[i][j] = max(dp[i][j], notMatch - maxMatch(neighbour, 0, i, adj, dp) + maxMatch(neighbour, 1, i, adj, dp) + 1);
    }
  } else {
    dp[i][j] = notMatch;
  }

  return dp[i][j];
}
int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<vector<int>> dp(n, vector<int>(2, -1));

  cout << max(maxMatch(0, 0, -1, adj, dp), maxMatch(0, 1, -1, adj, dp)) << endl;

  return 0;
}
