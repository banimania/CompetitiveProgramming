
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll getMax(const string &line) {
  int n = line.size();
  vector<vector<ll>> dp(n + 1, vector<ll>(13));

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 12; j++) {
      ll numTake = 0;
      if (j + 1 <= 12) {
        numTake = dp[i - 1][j + 1] * 10LL + (line[i - 1] - '0');
      }

      dp[i][j] = max(dp[i - 1][j], numTake);
    }
  }

  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i][0]);
  }
  return ans;
}

int main() {
  // cin.tie(0);
  // ios::sync_with_stdio(0);

  ll ans = 0;

  string line;
  while (getline(cin, line)) {

    string str = "";
    ll currLights = 0;
    ll currNum = 0;
    ll maxC = getMax(line);
    // for (int i = 0; i < (int) line.size() - 1; i++) {
    //   ll curr = (line[i] - '0') * 10LL;
    //   for (int j = i + 1; j < (int) line.size(); j++) {
    //     maxC = max(maxC, curr + (line[j] - '0'));
    //   }
    // }
    cout << "max = " << maxC << endl;
    ans += maxC;
  }

  cout << ans << "\n";

  return 0;
}
