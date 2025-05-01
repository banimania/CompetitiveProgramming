#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  
  set<int> ans = {0};
  for (int i = 1; i * i <= n; i++) {
    ans.insert(n / i);
    ans.insert(i);
  }
  cout << ans.size() << endl;
  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
