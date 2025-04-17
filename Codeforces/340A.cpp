#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  ll lcm = (x * y) / __gcd(x, y);

  ll first = (a / lcm + (a % lcm != 0)) * lcm;
  if (first < a || first > b) {
    cout << 0 << endl;
    return 0;
  }

  ll rem = b - first;

  ll ans = rem / lcm;

  cout << ans + 1 << endl;
  return 0;
}
