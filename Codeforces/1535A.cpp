#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> a(4);
  for (int i = 0; i < 4; i++) cin >> a[i];
  int w1 = max(a[0], a[1]), w2 = max(a[2], a[3]);
  sort(a.begin(), a.end());
  cout << ((w1 == a[3] && w2 == a[2]) || (w1 == a[2] && w2 == a[3]) ? "YES" : "NO") << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
