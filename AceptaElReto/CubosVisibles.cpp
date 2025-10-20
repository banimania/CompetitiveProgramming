#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;

    ll ans = n * n * n - ((n - 2) * (n - 2) * (n - 2));
    cout << ans << "\n";
  }
  return 0;
}
