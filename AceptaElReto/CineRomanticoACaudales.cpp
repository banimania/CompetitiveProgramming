#include <bits/stdc++.h>
using namespace std;

int solve(int t, int id, vector<pair<int, int>> &pelis, map<pair<int, int>, int> &dp) {
  if (dp.count({t, id})) return dp[{t, id}];
  dp[{t, id}] = 0;

  for (int i = id; i < pelis.size(); i++) {
    if (pelis[i].first >= t) {
      // veo la peli
      dp[{t, id}] = solve(pelis[i].first + pelis[i].second + 10, i + 1, pelis, dp) + pelis[i].second;

      // no veo la peli
      dp[{t, id}] = max(dp[{t, id}], solve(pelis[i].first, i + 1, pelis, dp));
      break;
    }
  }
  
  return dp[{t, id}];
}

int main() {
  int n;
  while (cin >> n && n) {
    vector<pair<int, int>> pelis(n);
    for (int i = 0; i < n; i++) {
      string tmp;
      cin >> tmp;

      int t = stoi(tmp.substr(0, 2)) * 60 + stoi(tmp.substr(3, 2));

      int d;
      cin >> d;

      pelis[i] = {t, d};
    }

    sort(pelis.begin(), pelis.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
      if (a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    });

    map<pair<int, int>, int> dp;

    cout << solve(0, 0, pelis, dp) << endl;
  }
  return 0;
}
