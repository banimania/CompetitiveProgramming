#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  while (cin >> t) {
    int n;
    cin >> n;

    vector<int> profundidad(n), oro(n);

    for (int i = 0; i < n; i++) {
      cin >> profundidad[i] >> oro[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));
    int ans = 0;

    vector<vector<tuple<int, int, bool>>> prev(n + 1, vector<tuple<int, int, bool>>(t + 1));
    
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= t; j++) {
        dp[i][j] = dp[i - 1][j];
        prev[i][j] = make_tuple(i - 1, j, false);
        if (j >= 3 * profundidad[i - 1]) {
          int coger = dp[i - 1][j - 3 * profundidad[i - 1]] + oro[i - 1];
          if (coger > dp[i][j]) {
            dp[i][j] = coger;
            prev[i][j] = make_tuple(i - 1, j - 3 * profundidad[i - 1], true);
          }
        }
      }
    }

    cout << dp[n][t] << endl;

    vector<int> cofres;
    pair<int, int> curr = {n, t};
    while (curr.first != 0 && curr.second != 0) {
      bool placed = get<2>(prev[curr.first][curr.second]);
      if (placed) {
        cofres.push_back(get<0>(prev[curr.first][curr.second]));
      }
      curr = {get<0>(prev[curr.first][curr.second]), get<1>(prev[curr.first][curr.second])};
    }
    reverse(cofres.begin(), cofres.end());
    cout << cofres.size() << endl;
    for (int i : cofres) {
      cout << profundidad[i] << " " << oro[i] << endl;
    }
    cout << "----" << endl;
  }
  return 0;
}
