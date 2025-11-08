#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  while (cin >> k >> n) {
    if (!k && !n) break;
    ll ans = 0;
    ll suma = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    int st = 0;
    for (int i = 0; i < n; i++) {
      suma += a[i];

      while (i - st + 1 > k) {
        suma -= a[st];
        st++;
      }
      ans = max(ans, suma);
    }
    cout << ans << "\n";
  }
  return 0;
}
