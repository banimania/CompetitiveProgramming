#include <bits/stdc++.h>
using namespace std;

struct State {
  int r1, r2, delay;
  bool operator==(const State &o) const {
    return r1 == o.r1 && r2 == o.r2 && delay == o.delay;
  }
};

struct Hash {
  size_t operator()(const State &s) const noexcept {
    return ((s.r1 * 131 + s.r2) * 131 + s.delay);
  }
};

int solve(int r1, int r2, int delay, const int n, const vector<pair<int, int>> &buts, const vector<vector<int>> &dist, unordered_map<State, int, Hash> &dp) {
  if (r1 == n + 1) return max(delay, dist[r2][n + 1]);

  State s = {r1, r2, delay};
  if (dp.count(s)) return dp[s];

  int d_next = dist[r1][r1 + 1];
  int wait = max(dist[r2][r1 + 1] - delay, 0);

  return dp[s] = min(
    solve(r1 + 1, r2, delay + d_next, n, buts, dist, dp),
    delay + solve(r1 + 1, r1, wait, n, buts, dist, dp)
  );
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int f, c, n;
  while (cin >> f >> c) {
    cin >> n;
    unordered_map<State, int, Hash> dp;
    vector<pair<int, int>> buts = vector<pair<int, int>>(n + 2, {0, 0});
    buts[0] = {1, 1};
    for (int i = 1; i <= n; i++) {
      cin >> buts[i].first >> buts[i].second;
    }
    buts[n + 1] = {f, c};

    vector<vector<int>> dist(n + 2, vector<int>(n + 2));
    for (int i = 0; i <= n + 1; i++) {
      for (int j = i; j <= n + 1; j++) {
        dist[i][j] = abs(buts[i].first - buts[j].first) + abs(buts[i].second - buts[j].second);
        dist[j][i] = dist[i][j];
      }
    }

    if (n == 0) {
      cout << dist[0][1] + 1 << endl;
      continue;
    }

    cout << solve(1, 0, dist[0][1], n, buts, dist, dp) + 1 << endl;
  }

  return 0;
}
