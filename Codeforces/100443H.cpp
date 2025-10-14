#include <bits/stdc++.h>
using namespace std;

int main() {
  int c;
  cin >> c;
  int n, p;
  cin >> n >> p;

  vector<pair<int, int>> shares(n);
  for (int i = 0; i < n; i++) {
    int a, t;
    cin >> a >> t;

    shares[i] = {a, t - a};
  }
  
  vector<pair<int, int>> pack(p);
  vector<pair<int, int>> fp;
  int gcd = 0;
  for (int i = 0; i < p; i++) {
    int r;
    cin >> r;

    int totalCost = 0, benefit = 0;

    for (int j = 0; j < r; j++) {
      int s, q;
      cin >> s >> q;
      s--;

      totalCost += shares[s].first * q;
      benefit += shares[s].second * q;
    }

    if (benefit <= 0) continue;

    fp.push_back({totalCost, benefit});
    gcd = __gcd(gcd, totalCost);
  }

  shares.clear();
  pack.clear();
  
  for (int i = 0; i < fp.size(); i++) {
    fp[i].first = (fp[i].first / gcd);
  }

  int scaledC = c / gcd;

  vector<int> dp(scaledC + 1, 0);
  for (const pair<int, int> &p : fp) {
    for (int j = scaledC; j >= p.first; j--) {
      dp[j] = max(dp[j], dp[j - p.first] + p.second);
    }
  }
  cout << dp[scaledC] << endl;

  return 0;
}
