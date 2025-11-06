#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<string> s(n);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < s[0].size(); i++) {
    for (int j = 0; j < n; j++) {
      cout << s[j][i];
    }
  }
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
