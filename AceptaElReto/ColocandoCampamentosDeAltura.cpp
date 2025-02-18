#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector<int> alturas(n + 1), costos(n + 1), dp(n + 1, INT_MAX);
    for (int i = 1; i < n + 1; i++) cin >> alturas[i];
    for (int i = 1; i < n + 1; i++) cin >> costos[i];

    int m;
    cin >> m;

    dp[0] = 0; // dp[i] = gasto minimo para llegar al campamento i
    for (int i = 1; i < n + 1; i++) {
      dp[i] = min(dp[i], dp[i - 1] + costos[i]);
      for (int j = i - 1; j >= 0; j--) {
        if (alturas[i] - alturas[j] > m) break;

        dp[i] = min(dp[i], dp[j] + costos[i]);
      }
    }

    cout << dp[n] << endl;
  }
  return 0;
}
