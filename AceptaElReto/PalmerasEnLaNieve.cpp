#include <bits/stdc++.h>
using namespace std;

void solve() {
  int kg, n;
  cin >> kg >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0, curr = 0;

  int st = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= kg) {
      curr++;

      if (curr >= 6) {
        for (int j = st; j < n; j++) {
          if (a[j] >= kg) {
            st = j + 1;
            curr--;
            break;
          }
        }
      }
    }

    if (curr <= 5) ans = max(ans, i - st + 1);
  }

  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
