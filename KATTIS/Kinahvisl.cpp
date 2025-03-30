#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != t[i]) cnt++;
  }
  cout << cnt + 1 << endl;
  return 0;
}
