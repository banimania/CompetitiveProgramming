#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int maxH = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] > maxH) {
        maxH = a[i];
        ans++;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
