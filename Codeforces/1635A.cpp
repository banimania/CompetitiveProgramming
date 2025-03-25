#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio();
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int ans = 0, x;
    for (int i = 0; i < n; i++) {
      cin >> x;
      ans |= x;
    }

    cout << ans << endl;
  }

  return 0;
}
