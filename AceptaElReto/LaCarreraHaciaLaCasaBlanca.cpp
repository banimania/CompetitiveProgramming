#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n) {
    int delegados = 0;
    vector<pair<int, int>> estados; 
    for (int i = 0; i < n; ++i) {
      int d, trump, kamala, ind;
      cin >> d >> trump >> kamala >> ind;

      delegados += d;

      int total = trump + kamala + ind;
      int needed = (total / 2) + 1;

      int neededExtra = max(needed - trump, 0);

      if (ind >= neededExtra) {
        estados.push_back({d, neededExtra});
      }
    }

    int needed = delegados / 2 + 1;
    vector<int> dp(delegados + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < estados.size(); ++i) {
      for (int j = delegados; j >= estados[i].first; --j) {
        if (dp[j - estados[i].first] != INT_MAX) {
          dp[j] = min(dp[j], dp[j - estados[i].first] + estados[i].second);
        }
      }
    }
    int ans = INT_MAX;
    for (int j = needed; j <= delegados; ++j) {
      ans = min(ans, dp[j]);
    }

    if (ans == INT_MAX) {
      cout << "IMPOSIBLE\n";
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
