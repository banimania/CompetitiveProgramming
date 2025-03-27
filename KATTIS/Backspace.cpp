#include <bits/stdc++.h>
using namespace std;

int main() {
  char c;
  string ans;
  while (cin >> c) {
    if (c == '<') {
      if (!ans.empty()) ans.pop_back();
    } else ans.push_back(c);
  }
  cout << ans << endl;
  return 0;
}
