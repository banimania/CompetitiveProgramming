#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> pref(n);
    for (int i = 0; i < n; i++) {
      int x = 0;
      cin >> x;

      pref[i] = x + (i > 0 ? pref[i - 1] : 0);
    }

    int best = abs(pref[n - 1]);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
      int fh = pref[i - 1];
      int sh = pref[n - 1] - pref[i - 1];

      int proposed = abs(fh - sh);

      if (proposed < best) {
        best = proposed;
        ans = i;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
