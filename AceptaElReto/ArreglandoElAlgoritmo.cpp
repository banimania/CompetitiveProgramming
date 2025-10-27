#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    ll maxi = LLONG_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;

      if (maxi > x) ans = i + 1;
      else maxi = x;
    }

    ans = n - ans;

    cout << ans << "\n";
  }
  return 0;
}
