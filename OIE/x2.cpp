#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    ll ans = 0;
    ll suma = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      suma += a[i];
    }

    for (int i = 0; i < n; i++) {
      suma -= a[i];

      ans += a[i] * suma;
    }


    cout << ans << "\n";
  }
  return 0;
}
