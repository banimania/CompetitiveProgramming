// https://cses.fi/problemset/task/1674

#include <bits/stdc++.h>
using namespace std;

int dfs(int curr, vector<vector<int>> &adj, vector<int> &dp) {
  if (dp[curr] != -1) return dp[curr];

  dp[curr] = 0;

  for (int neighbour : adj[curr]) {
    dp[curr] += dfs(neighbour, adj, dp) + 1;
  }

  return dp[curr];
}

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);

  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    x--;

    adj[x].push_back(i);
  }

  vector<int> dp(n, -1);

  for (int i = 0; i < n; i++) {
    cout << dfs(i, adj, dp) << " ";
  }
  cout << endl;
  return 0;
}
