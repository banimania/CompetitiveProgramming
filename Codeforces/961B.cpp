#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;

  vector<ll> prefAll(n), pref1(n);

  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    pref1[i] = (i > 0 ? pref1[i - 1] : 0) + (x ? v[i] : 0);
    prefAll[i] = (i > 0 ? prefAll[i - 1] : 0) + v[i];
  }
  
  ll ans = 0;
  for (int i = 0; i <= n - k; i++) {
    ll currentWindow = prefAll[i + k - 1] - (i > 0 ? prefAll[i - 1] : 0);

    ll pastWindow = 0, nextWindow = 0;
    if (i > 0) {
      pastWindow = pref1[i - 1];
    }
    if (i < n - k) {
      nextWindow = pref1[n - 1] - pref1[i + k - 1];
    }

    ans = max(ans, pastWindow + currentWindow + nextWindow);
  }
  cout << ans << "\n";

  return 0;
}
