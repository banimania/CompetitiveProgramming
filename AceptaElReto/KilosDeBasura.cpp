#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool works(int t, int k, vector<pair<char, int>> &v) {
  int veces = 0;
  int tamE = 2 * t;
  int tamR = t;

  int e = 0, r = 0;
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

    int low = 1;
    int high = 2 * 1e9 + 5;

    int ans = high;
    while (high >= low) {
      int mid = (high - low) / 2 + low;

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
