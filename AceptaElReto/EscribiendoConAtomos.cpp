#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 0

set<string> elementos = {
  "h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al",
  "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe",
  "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr",
  "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn",
  "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir",
  "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf",
  "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "nh", "fl", "mc", "lv",
  "ts", "og", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy",
  "ho", "er", "tm", "yb", "lu", "ac", "th", "pa", "u", "np", "pu", "am", "cm",
  "bk", "cf", "es", "fm", "md", "no", "lr"
};

void solve(int tt) {
  string line;
  while (getline(cin, line)) {
    string input;
    for (int i = 0; i < line.size(); i++) {
      if (line[i] != ' ') {
        input.push_back(tolower(line[i]));
      }
    }

    vector<bool> dp(input.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= input.size(); i++) {
      string one = input.substr(i - 1, 1), two;
      if (i > 1) two = input.substr(i - 2, 2);

      dp[i] = (elementos.count(one) && dp[i - 1]) || (elementos.count(two) && dp[i - 2]);
    }

    cout << (dp[input.size()] ? "SI" : "NO") << endl;
  }
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
