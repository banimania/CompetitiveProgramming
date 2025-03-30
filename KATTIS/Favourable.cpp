#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dfs(ll current, map<ll, vector<ll>> &adj, map<ll, ll> &dp) {
  if (dp.count(current)) return dp[current];

  ll ans = 0;
  for (int neighbour : adj[current]) {
    ans += dfs(neighbour, adj, dp);
  }
  return dp[current] = ans;
}

void solve() {
  ll n;
  cin >> n;

  map<ll, vector<ll>> adj;
  map<ll, ll> dp;

  cin.ignore();
  string line;
  for (int i = 0; i < n; i++) {
    getline(cin, line);

    istringstream iss(line);
    vector<string> v;

    string s;
    while (iss >> s) {
      v.push_back(s);
    }

    ll section = stoll(v[0]);
    if (v.size() == 2) {
      if (v[1] == "favourably") dp[section] = 1;
    } else {
      ll o1 = stoll(v[1]), o2 = stoll(v[2]), o3 = stoll(v[3]);
      adj[section] = {o1, o2, o3};
    }
  }

  cout << dfs(1, adj, dp) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
