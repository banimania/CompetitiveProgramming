#include <bits/stdc++.h>
using namespace std;

#define TESTCASES false 

void solve() {
  string s;
  while (getline(cin, s)) {
    string res;

    int cursor = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '-') {
        cursor = 0;
      } else if (s[i] == '+') {
        cursor = res.length();
      } else if (s[i] == '*') {
        cursor = min((int) res.length(), cursor + 1);
      } else if (s[i] == '3') {
        if (cursor + 1 <= res.length()) {
          res.erase(res.begin() + cursor);
        }
      } else {
        res.insert(res.begin() + cursor, s[i]), cursor++;
      }
    }

    cout << res << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
