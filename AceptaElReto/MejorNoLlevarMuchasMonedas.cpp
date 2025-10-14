#include <bits/stdc++.h>
using namespace std;

int solve(int pos, int money, vector<int> &coins, vector<int> &quant, int p, vector<vector<pair<int,int>>> &dp) {
  if (money == p) return 0;
  if (money > p) return 9999;
  if (pos == coins.size() && money < p) return 9999;

  if (dp[pos][money].first != -1) return dp[pos][money].first;

  dp[pos][money] = {9999, 0};

  for (int take = quant[pos]; take >= 0; take--) {
    if (money + take * coins[pos] > p) continue;
    int opt = solve(pos + 1, money + take * coins[pos], coins, quant, p, dp) + take;
    if (opt < dp[pos][money].first) {
      dp[pos][money] = {opt, take};
    }
  }

  return dp[pos][money].first;
}

int main() {
  int n;
  while (cin >> n) {
    vector<int> coins(n), quant(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 0; i < n; i++) cin >> quant[i];
    int p;
    cin >> p;

    vector<vector<pair<int,int>>> dp(n + 1, vector<pair<int,int>>(p + 1, {-1, 0}));

    int s = solve(0, 0, coins, quant, p, dp);
    if (s == 9999) {
      cout << "NO\n";
      continue;
    }

    cout << "SI";

    int pos = 0, money = 0;
    while (pos < n) {
      int curr = dp[pos][money].second;
      cout << " " << curr;
      money += curr * coins[pos];
      pos++;
    }
    cout << "\n";
  }
  return 0;
}
