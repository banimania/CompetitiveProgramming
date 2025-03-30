#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int as = s.size() - 1, at = t.size() - 1;

  cout << (as >= at ? "go" : "no") << endl;
  return 0;
}
