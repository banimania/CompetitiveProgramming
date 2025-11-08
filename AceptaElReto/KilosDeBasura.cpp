#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool works(ll t, ll k, vector<pair<char, int>> &v) {
  ll veces = 0;
  ll tamE = 2 * t;
  ll tamR = t;

  ll e = 0, r = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first == 'E') {
      if (v[i].second > tamE) return false;
      if (e + v[i].second <= tamE) {
        e += v[i].second;
      } else {
        veces++;
        e = v[i].second;
        r = 0;
      }
    } else {
      if (v[i].second > tamR) return false;
      if (r + v[i].second <= tamR) {
        r += v[i].second;
      } else {
        veces++;
        r = v[i].second;
        e = 0;
      }
    }
  }

  if (e || r) veces++;

  return veces <= k;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll k, n;
  while (cin >> k >> n) {
    if (!k && !n) break;

    vector<pair<char, int>> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i].second>> v[i].first;
    }

    ll low = 1;
    ll high = 3 * 1e9;

    ll ans = high;
    while (high >= low) {
      ll mid = (high - low) / 2 + low;

      if (works(mid, k, v)) {
        high = mid - 1;
        ans = mid;
      } else {
        low = mid + 1;
      }
    }

    cout << ans << "\n";
  }
  return 0;
}
