#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll c, n, p;
  cin >> c >> n >> p;

  vector<pair<ll, ll>> shares(n);
  for (int i = 0; i < n; i++) {
    cin >> shares[i].first >> shares[i].second;
  }

  vector<ll> profit, cost;
  for (int i = 0; i < p; i++) {
    ll numShares;
    cin >> numShares;
    ll currentProfit = 0, currentCost = 0;
    for (int j = 0; j < numShares; j++) {
      ll id, quant;
      cin >> id >> quant;
      id--;
      currentProfit += (shares[id].second - shares[id].first) * quant;
      currentCost += shares[id].first * quant;
    }
    if (currentProfit > 0) {
      profit.push_back(currentProfit);
      cost.push_back(currentCost);
    }
  }

  map<ll, ll> dp;
  dp[0] = 0;
  ll ans = 0;

  for (int i = 0; i < profit.size(); i++) {
    vector<pair<ll, ll>> updates;
    for (auto &[money, value] : dp) {
      ll newMoney = money + cost[i];
      if (newMoney <= c) {
        updates.push_back({newMoney, value + profit[i]});
      }
    }
    for (auto &[newMoney, newValue] : updates) {
      if (dp.find(newMoney) == dp.end() || dp[newMoney] < newValue) {
        dp[newMoney] = newValue;
        ans = max(ans, newValue);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
