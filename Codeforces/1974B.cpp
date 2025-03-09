#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  set<char> chars;
  string diff;
  for (int i = 0; i < n; i++) {
    if (!chars.count(s[i])) {
      chars.insert(s[i]);
      diff.push_back(s[i]);
    }
  }

  sort(diff.begin(), diff.end());
  map<char, char> code;

  for (int i = 0; i < diff.size(); i++) {
    code[diff[i]] = diff[diff.size() - i - 1];
  }

  for (int i = 0; i < n; i++) {
    cout << code[s[i]];
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
