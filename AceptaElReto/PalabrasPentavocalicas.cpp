#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define TESTCASES 1

set<char> vocales = {'a', 'e', 'i', 'o', 'u'};
void solve(int tt) {
  string s;
  cin >> s;

  set<char> vistas;
  for (int i = 0; i < s.size(); i++) {
    if (vocales.count(s[i])) vistas.insert(s[i]);
  }

  cout << (vistas.size() == 5 ? "SI" : "NO") << endl;
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    solve(tt);
  }
  return 0;
}
