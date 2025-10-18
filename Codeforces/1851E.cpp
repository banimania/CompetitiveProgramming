#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 1

typedef long long ll;

ll getMinPrice(int potion, vector<int> &cost, vector<vector<int>> &fabrication, vector<ll> &dp) {
  if (dp[potion] != -1) return dp[potion];

  dp[potion] = cost[potion];

  if (!fabrication[potion].empty()) {
    ll mix = 0;
    for (int i = 0; i < fabrication[potion].size(); i++) {
      mix += getMinPrice(fabrication[potion][i], cost, fabrication, dp);
    }
    if (dp[potion] > mix) {
      dp[potion] = mix;
    }
  }

  return dp[potion];
}

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> cost(n);
  for (int i = 0; i < n; i++) cin >> cost[i];
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    x--;

    cost[x] = 0;
  }

  vector<vector<int>> fabrication(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x) {
      for (int j = 0; j < x; j++) {
        int idx;
        cin >> idx;
        idx--;

        fabrication[i].push_back(idx);
      }
    }
  }

  vector<ll> dp(n, -1);
  for (int i = 0; i < n; i++) {
    cout << getMinPrice(i, cost, fabrication, dp) << " ";
  }
  cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
