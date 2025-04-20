// https://cses.fi/problemset/task/1133

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> dfs(ll curr, ll dist, vector<vector<ll>> &adj, vector<bool> &visited, vector<ll> &cnt, vector<ll> &dp) {
  ll currCnt = 1, currDist = 0;

  for (ll neighbour : adj[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;

      auto [neighbourCnt, neighbourDist] = dfs(neighbour, dist + 1, adj, visited, cnt, dp);

      currCnt += neighbourCnt;
      currDist += neighbourDist + dist;
    }
  }
  
  cnt[curr] = currCnt;
  dp[curr] = currDist;
  return {currCnt, currDist};
}

void dfs2(ll curr, ll n, vector<vector<ll>> &adj, vector<bool> &visited, vector<ll> &cnt, vector<ll> &dp) {
  for (ll neighbour : adj[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;

      dp[neighbour] = dp[curr] - cnt[neighbour] + (n - cnt[neighbour]);
      dfs2(neighbour, n, adj, visited, cnt, dp);
    }
  }
}

int main() {
  ll n;
  cin >> n;

  vector<vector<ll>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;

    a--, b--;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  vector<ll> cnt(n), dp(n);

  vector<bool> visited(n);
  visited[0] = true;

  dfs(0, 1, adj, visited, cnt, dp);

  visited = vector<bool>(n);
  visited[0] = true;

  dfs2(0, n, adj, visited, cnt, dp);

  for (int i = 0; i < n; i++) {
    cout << dp[i] << " ";
  }
  cout << endl;

  return 0;
}
