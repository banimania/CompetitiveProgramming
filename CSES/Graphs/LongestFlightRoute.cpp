// https://cses.fi/problemset/task/1680

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 0

struct State {
  ll city, dist;
};

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<ll>> adj(n);
  for (int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;

    adj[u].push_back(v);
  }

  vector<ll> longestDist(n, INT_MIN), prev(n, -1);
  stack<State> st;
  
  longestDist[0] = 1;
  st.push({0, 1});
  
  while (!st.empty()) {
    State current = st.top();
    st.pop();

    for (ll neighbour : adj[current.city]) {
      if (longestDist[neighbour] < current.dist + 1) {
        prev[neighbour] = current.city;
        longestDist[neighbour] = current.dist + 1;
        st.push({neighbour, current.dist + 1});
      }
    }
  }

  if (longestDist[n - 1] == INT_MIN) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  cout << longestDist[n - 1] << endl;

  vector<ll> route;
  ll current = n - 1;
  while (current) {
    route.push_back(current);
    current = prev[current];
  }
  route.push_back(0);

  reverse(route.begin(), route.end());

  for (ll i : route) {
    cout << i + 1 << " ";
  }
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
