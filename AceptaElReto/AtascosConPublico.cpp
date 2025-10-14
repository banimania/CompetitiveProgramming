#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> g(n);
    vector<ll> dp(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }

    for (int i = n - 1; i >= 0; i--) {
      dp[i] = max((i + k + 1 < n ? dp[i + k + 1] : 0) + g[i], (i + 1 < n ? dp[i + 1] : 0));
    }

    cout << dp[0] << '\n';
  }
  return 0;
}
