#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

int solve(int i, const vector<string> &codes, const string &str, vector<int> &dp, int &maxLen) {
  if (i == str.size()) return 1;
  if (dp[i] != -1) return dp[i];

  dp[i] = 0;

  for (int j = i; j < min(i + maxLen, (int) str.size()); j++) {
    string substr = str.substr(i, j - i + 1);

    for (const string &code : codes) {
      if (substr == code) {
        dp[i] = ((ll) dp[i] + solve(j + 1, codes, str, dp, maxLen)) % MOD;
      }
    }
  }

  return dp[i];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int n;
  while (cin >> n && n) {
    ll result = 1;

    vector<string> codes(n);
    int maxLen = -1;
    for (int i = 0; i < n; i++) {
      cin >> codes[i];
      maxLen = max(maxLen, (int) codes[i].size());
    }

    string code;
    cin >> code;
    code += "0";

    string last = "";
    for (int i = 0; i < code.size(); i++) {
      if (code[i] != '0') {
        last += code[i];
      } else {
        if (!last.empty()) {
          vector<int> dp(last.size(), -1);
          result = (result * solve(0, codes, last, dp, maxLen)) % MOD;
          last = "";
        }
      }
    }

    cout << result << endl;
  }
  return 0;
}
