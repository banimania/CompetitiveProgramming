#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 0

void solve(int tt) {
  ll n;
  cin >> n;

  vector<vector<ll>> adj(n);
  for (int i = 1; i < n; i++) {
    ll x;
    cin >> x;
    x--;

    adj[x].push_back(i);
  }

  vector<ll> prev(n, -1);
  queue<ll> q;
  q.push(0);
  while (!q.empty()) {
    ll curr = q.front();
    q.pop();

    if (curr == n - 1) {
      break;
    }

    for (ll neighbour : adj[curr]) {
      if (prev[neighbour] == -1) {
        prev[neighbour] = curr;
        q.push(neighbour);
      }
    }
  }

  vector<ll> path;
  ll curr = n - 1;
  while (prev[curr] != -1) {
    path.push_back(curr + 1);
    curr = prev[curr];
  }
  path.push_back(1);
  reverse(path.begin(), path.end());

  for (int i = 0; i < path.size(); i++) {
    cout << path[i] << " ";
  }
  cout << endl;
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
