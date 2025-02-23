#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void solve() {
  int o, c;
  cin >> o >> c;

  map<pair<int, int>, double> dp;
  map<int, pair<double, double>> objects;
  for (int i = 0; i < o; i++) {
    int id;
    double x, y;
    cin >> id >> x >> y;

    objects[id] = {x, y};
    dp[{id, id}] = 0;
  }

  map<int, vector<int>> adj;
  for (int i = 0; i < c; i++) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);

    double dist = sqrt(abs(objects[u].first - objects[v].first) * abs(objects[u].second - objects[v].second));
    dp[{u, v}] = min(dist, (dp.count({u, v}) ? dp[{u, v}] : DBL_MAX));
    dp[{v, u}] = min(dist, (dp.count({v, u}) ? dp[{v, u}] : DBL_MAX));
  }

  for (pair<int, pair<double, double>> oK : objects) {
    for (pair<int, pair<double, double>> oI : objects) {
      for (pair<int, pair<double, double>> oJ : objects) {
        int i = oI.first;
        int j = oJ.first;
        int k = oK.first;

        if (!dp.count({i, j})) dp[{i, j}] = DBL_MAX;
        if (dp.count({i, k}) && dp.count({k, j}) && dp[{i, k}] != DBL_MAX && dp[{k, j}] != DBL_MAX) {
          dp[{i, j}] = min(dp[{i, j}], dp[{i, k}] + dp[{k, j}]);
        }
      }
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;

    cout << setw(4) << setfill('0') << u << " ";
    cout << setw(4) << setfill('0') << v << " ";
    cout << setprecision(4) << dp[{u, v}] << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
