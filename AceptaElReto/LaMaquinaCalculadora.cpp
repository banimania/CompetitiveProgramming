#include <bits/stdc++.h>
using namespace std;

int minOps(int i, vector<int> &dp) {
  if (dp[i] != -1) return dp[i];

  dp[i] = INT_MAX;

  if (i > 0 && minOps(i - 1, dp) != INT_MAX) dp[i] = min(dp[i], minOps(i - 1, dp) + 1); // + 1
  if (i % 2 == 0 && minOps(i / 2, dp) != INT_MAX) dp[i] = min(dp[i], minOps(i / 2, dp) + 1); // * 2
  if (i * 3 < dp.size() && minOps(i * 3, dp) != INT_MAX) dp[i] = min(dp[i], minOps(i * 3, dp) + 1); // / 3

  return dp[i];
}

// int minOps(int i, vector<int> &dp) {
//   cout << i << endl;
//   if (dp[i] != INT_MAX) return dp[i];

//   int minusOne = (10000 + ((i - 1) % 10000)) % 10000;
//   int dividedTwo = (i / 2) % 10000;
//   int timesThree = (i * 3) % 10000;

//   return dp[i] = min({
//     minOps(minusOne, dp) + 1,
//     minOps(dividedTwo, dp) + 1,
//     minOps(timesThree, dp) + 1
//   });
// }

// TODO: arreglar, si lees el enunciado pone que las operaciones se hacen módulo 10k y las divisiones son enteras

int main() {
  int a, b;
  while (cin >> a >> b) {
    vector<int> dp(10001, -1);
    dp[a] = 0;

    cout << minOps(b, dp) << endl;
  }
  return 0;
}
