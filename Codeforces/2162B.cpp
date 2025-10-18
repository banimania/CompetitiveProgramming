#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int k = 0;

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (s[i] == '0') {
      k++;
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] + 1 << " ";
  }
  cout << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
