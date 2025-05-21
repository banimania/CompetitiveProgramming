// https://cses.fi/problemset/task/1688
 
#include <bits/stdc++.h>
using namespace std;
 
void dfs(int curr, vector<int> &tin, vector<int> &tout, int &timer, vector<vector<int>> &adj) {
  tin[curr] = ++timer;

  for (int child : adj[curr]) {
    dfs(child, tin, tout, timer, adj);
  }
  
  tout[curr] = ++timer;
}

void precalc(vector<int> &parent, vector<vector<int>> &up, vector<int> &tin, vector<int> &tout, vector<vector<int>> &adj) {
  for (int i = 0; i < (int) parent.size(); i++) {
    up[i][0] = parent[i];
  }
 
  for (int j = 1; j < 32; j++) {
    for (int i = 0; i < (int) parent.size(); i++) {
      if (up[i][j - 1] != -1) {
        up[i][j] = up[up[i][j - 1]][j - 1];
      }
    }
  }

  int timer = 0;
  dfs(0, tin, tout, timer, adj);
}
 
bool ancestor(int u, int v, vector<int> &tin, vector<int> &tout) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int query(int u, int v, vector<vector<int>> &up, vector<int> &tin, vector<int> &tout) {
  if (ancestor(u, v, tin, tout)) return u;
  if (ancestor(v, u, tin, tout)) return v;
  for (int i = 31; i >= 0; i--) {
    if (up[u][i] != -1 && !ancestor(up[u][i], v, tin, tout)) u = up[u][i];
  }
  return up[u][0];
}
 
int main() {
  int n, q;
  cin >> n >> q;
 
  vector<int> parent(n, -1);
  vector<vector<int>> adj(n);
 
  for (int i = 1; i < n; i++) {
    cin >> parent[i];
    parent[i]--;

    adj[parent[i]].push_back(i);
  }
 
  vector<vector<int>> up(n, vector<int>(32, -1));
  vector<int> tin(n), tout(n);
  precalc(parent, up, tin, tout, adj);
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
 
    cout << query(u - 1, v - 1, up, tin, tout) + 1 << endl;
  }
  return 0;
}
