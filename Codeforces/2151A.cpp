#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }

  bool sorted = true;
  for (int i = 1; i < m; i++) {
    if (a[i] <= a[i - 1]) {
      sorted = false;
      break;
    }
  }

  if (!sorted) {
    cout << 1 << endl;
    return;
  }

  int ma = 0;
  for (int i = 0; i < m; i++) {
    ma = max(ma, a[i]);
  }
  
  cout << (n - ma + 1) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
