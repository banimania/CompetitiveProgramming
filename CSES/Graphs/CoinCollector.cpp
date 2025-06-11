#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int curr, vector<vector<int>> &adj, stack<int> &topo, vector<bool> &visited) {
  for (int neighbour : adj[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      dfs(neighbour, adj, topo, visited);
    }
  }
  topo.push(curr);
}

void dfsSCC(int curr, vector<vector<int>> &adjT, vector<int> &coins, vector<int> &sccId, vector<ll> &sccCoins) {
  for (int neighbour : adjT[curr]) {
    if (sccId[neighbour] == -1) {
      sccId[neighbour] = sccId[curr];
      sccCoins[sccId[neighbour]] += coins[neighbour];
      dfsSCC(neighbour, adjT, coins, sccId, sccCoins);
    }
  }
}

void dfsDAG(int curr, vector<vector<int>> &adj, vector<int> &sccId, vector<set<int>> &adjDAG) {
  for (int neighbour : adj[curr]) {
    if (sccId[curr] != sccId[neighbour]) {
      adjDAG[sccId[curr]].insert(sccId[neighbour]);
    }
  }
}

void dfsTopoDAG(int curr, vector<set<int>> &adjDAG, stack<int> &topo, vector<bool> &visited) {
  for (int neighbour : adjDAG[curr]) {
    if (!visited[neighbour]) {
      visited[neighbour] = true;
      dfsTopoDAG(neighbour, adjDAG, topo, visited);
    }
  }

  topo.push(curr);
}

ll maxCoins(int curr, vector<set<int>> &adj, vector<ll> &sccCoins, vector<ll> &dp) {
  if (dp[curr] != LLONG_MIN) return dp[curr];
  
  dp[curr] = sccCoins[curr];

  for (int neighbour : adj[curr]) {
    dp[curr] = max(dp[curr], sccCoins[curr] + maxCoins(neighbour, adj, sccCoins, dp));
  }

  return dp[curr];
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> coins(n);

  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }

  vector<vector<int>> adj(n), adjT(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    u--, v--;

    adj[u].push_back(v);
    adjT[v].push_back(u);
  }

  vector<bool> visited(n);
  stack<int> topo;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfs(i, adj, topo, visited);
    }
  }

  vector<int> sccId(n, -1);
  vector<ll> sccCoins;
  int currSCC = 0;
  while (!topo.empty()) {
    int i = topo.top();
    topo.pop();

    if (sccId[i] == -1) {
      sccId[i] = currSCC;
      sccCoins.push_back(coins[i]);
      dfsSCC(i, adjT, coins, sccId, sccCoins);

      currSCC++;
    }
  }

  vector<set<int>> adjDAG(currSCC);
  fill(visited.begin(), visited.end(), false);
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfsDAG(i, adj, sccId, adjDAG);
    }
  }

  visited = vector<bool>(currSCC);
  for (int i = 0; i < currSCC; i++) {
    if (!visited[i]) {
      visited[i] = true;
      dfsTopoDAG(i, adjDAG, topo, visited);
    }
  }

  ll ans = LLONG_MIN;
  vector<ll> dp(n, LLONG_MIN);
  while (!topo.empty()) {
    int i = topo.top();
    topo.pop();

    ans = max(ans, maxCoins(i, adjDAG, sccCoins, dp));
  }

  cout << ans << endl;
  return 0;
}
