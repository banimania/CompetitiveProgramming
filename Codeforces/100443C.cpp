#include <bits/stdc++.h>
using namespace std;

struct Place {
  int floor, x, y;
};

double euclideanDist(Place &a, Place &b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(5 * a.floor - 5 * b.floor, 2));
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<Place> places(n);

  for (int i = 0; i < n; i++) {
    cin >> places[i].floor >> places[i].x >> places[i].y;
  }

  vector<vector<double>> dp(n, vector<double>(n, DBL_MAX));
  vector<vector<int>> prev(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    dp[i][i] = 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      prev[i][j] = j;
    }
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    string s;
    cin >> u >> v >> s;


    if (s == "walking" || s == "stairs") {
      double dist = euclideanDist(places[u], places[v]);
      if (dp[u][v] > dist) {
        dp[u][v] = dist;
        prev[u][v] = v;
      }
      if (dp[v][u] > dist) {
        dp[v][u] = dist;
        prev[v][u] = u;
      }
    } else if (s == "lift") {
      double dist = 1;
      if (dp[u][v] > dist) {
        dp[u][v] = dist;
        prev[u][v] = v;
      }
      if (dp[v][u] > dist) {
        dp[v][u] = dist;
        prev[v][u] = u;
      }
    } else if (s == "escalator") {
      double dist1 = euclideanDist(places[u], places[v]);
      double dist2 = 3 * euclideanDist(places[u], places[v]);
      if (dp[u][v] > dist1) {
        dp[u][v] = dist1;
        prev[u][v] = v;
      }
      if (dp[v][u] > dist2) {
        dp[v][u] = dist2;
        prev[v][u] = u;
      }
    }
  }

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (dp[i][k] != DBL_MAX && dp[k][j] != DBL_MAX && dp[i][j] > dp[i][k] + dp[k][j]) {
          dp[i][j] = dp[i][k] + dp[k][j];
          prev[i][j] = prev[i][k];
        }
      }
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;

    vector<int> path = {u};
    while (u != v) {
      u = prev[u][v];
      path.push_back(u);
    }

    for (int i = 0; i < path.size(); i++) {
      cout << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    cout << endl;
  }

  return 0;
}
