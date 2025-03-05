#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 1

ll minSteps(ll n, map<ll, ll> &dp) {
  if (dp.count(n)) return dp[n];

  if (n % 25 == 0) return dp[n] = 0;
  if (n <= 10) return dp[n] = 1;

  dp[n] = INT_MAX;

  string nStr = to_string(n);
  for (int i = 0; i < nStr.size(); i++) {
    string newNStr = nStr.substr(0, i) + nStr.substr(i + 1, nStr.size() - i - 1);
    ll newN = stoll(newNStr);
    dp[n] = min(dp[n], minSteps(newN, dp) + 1);
  }

  return dp[n];
}

map<ll, ll> dp;

void solve(int tt) {
  ll n;
  cin >> n;

  cout << minSteps(n, dp) << endl;
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
