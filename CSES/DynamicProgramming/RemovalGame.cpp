#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maxScore(ll i, ll j, vector<ll> &a, ll sum, vector<vector<ll>> &dp) {
  if (dp[i][j] != LLONG_MIN) return dp[i][j];

  if (i == j) return dp[i][j] = a[i];

  return dp[i][j] = max(sum - maxScore(i + 1, j, a, sum - a[i], dp), sum - maxScore(i, j - 1, a, sum - a[j], dp));
}

int main() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll sum = 0;
  for (int i = 0; i < n; i++) sum += a[i];

  vector<vector<ll>> dp(n, vector<ll>(n, LLONG_MIN));

  cout << maxScore(0, n - 1, a, sum, dp) << endl;

  return 0;
}
