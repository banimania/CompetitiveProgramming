#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t, e;
  while (cin >> t >> e) {
    if (!t && !e) break;
    
    vector<int> anden(e);
    for (int i = 0; i < e; i++) {
      cin >> anden[i];
    }
    
    vector<ll> suf(e, 0), pref(e, 0);
    for (int i = e - 1; i > 0; i--) {
      suf[i - 1] += (anden[i] + suf[i]);
    }
    for (int i = e - 1; i > 0; i--) {
      suf[i - 1] += suf[i];
    }

    for (int i = 0; i < e - 1; i++) {
      pref[i + 1] += (anden[i] + pref[i]);
    }
    for (int i = 0; i < e - 1; i++) {
      pref[i + 1] += pref[i];
    }
    
    ll ans = suf[t - 1];
    for (int i = 1; i <= e - t; i++) {
      ans = min(ans, suf[t - 1 + i] + pref[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
