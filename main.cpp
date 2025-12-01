#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 1

void solve() {
  string s;
  cin >> s;

  bool ans = false;
  for (int i = 1; i < s.size() / 2; i++) {
    if (s[i] != s[i - 1]) {
      ans = true;
      break;
    }
  }

  cout << (ans ? "YES\n" : "NO\n");
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;

  while (t--) solve();
  return 0;
}
