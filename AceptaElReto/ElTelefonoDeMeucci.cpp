#include <bits/stdc++.h>
using namespace std;

static const string codes[] = {
  "X", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<string> start[256];
  for (int i = 0; i < 10; ++i) {
    start[(unsigned char) codes[i][0]].push_back(codes[i]);
  }

  string code;
  while (cin >> code) {
    const int n = code.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
      const vector<string> &v = start[(unsigned char) code[i]];
      if (v.empty()) continue;

      for (size_t k = 0; k < v.size(); ++k) {
        const string &pat = v[k];
        int len = pat.size();

        if (i + len <= n && code.compare(i, len, pat) == 0) {
          dp[i] += dp[i + len];
        }
      }
    }

    cout << dp[0] << '\n';
  }

  return 0;
}
