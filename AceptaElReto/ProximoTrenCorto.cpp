#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, e;
  while (cin >> t >> e) {
    if (!t && !e) break;
    
    vector<int> a(e);
    for (int i = 0; i < e; i++) cin >> a[i];

    vector<int> pSum(e);
    pSum[0] = a[0];
    for (int i = 1; i < e; i++) pSum[i] = a[i] + pSum[i - 1];

    int curr = 0;
    for (int i = t; i < e; i++) curr += a[i] * (i - t + 1);

    int ans = INT_MAX;

    for (int i = 1; i <= e - t; i++) {
      curr += pSum[i - 1];
      curr -= (pSum[e - 1] - pSum[i + t - 2]);

      ans = min(ans, curr);
    }

    cout << ans << endl;
  }
  return 0;
}
