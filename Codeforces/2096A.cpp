#include <bits/stdc++.h>
using namespace std;

void solve() {
  int neg = 0, pos = 0;
  int n;
  string s;
  cin >> n >> s;
  vector<int> ans(n);
  ans[0] = 0;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '>') {
      pos++;
      ans[i + 1] = pos;
    } else {
      neg--;
      ans[i + 1] = neg;
    }
  }

  int x = -neg;
  for (int i = 0; i < n; i++) {
    cout << x + ans[i] + 1 << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}
