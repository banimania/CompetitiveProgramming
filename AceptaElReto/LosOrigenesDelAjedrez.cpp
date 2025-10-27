#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  while (cin >> a >> b >> c) {
    if (!a && !b && !c) break;

    ll ans = a;

    ll prev = a;

    for (int i = 2; i <= c; i++) {
      prev *= b;
      ans += prev;
    }

    cout << ans << "\n";
  }
  return 0;
}
