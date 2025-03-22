#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int ks = 0, bs = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'k') ks++;
    else if (s[i] == 'b') bs++;
  }

  string ans = "none";
  if (ks || bs) {
    if (ks == bs) ans = "boki";
    else ans = (ks > bs ? "kiki" : "boba"); 
  }
  cout << ans << endl;
  return 0;
}
