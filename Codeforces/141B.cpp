#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(ll a, ll x, ll y) {
  if (y % a == 0) return -1;

  if (y > 0 && y < a) {
    if (x > -a / 2.0 && x < a / 2.0) {
      return 1;
    }

    return -1;
  } else if (y > a) {

    if ((y / a) % 2 == 1) {
      if (x > -a / 2.0 && x < a / 2.0) {
        return ((y / a) / 2) * 3 + 2;
      }
      return -1;
    } else {
      if (x > -a && x < 0) {
        return ((y / a - 1) / 2) * 3 + 2 + 1;
      } else if (x > 0 && x < a) {
        return ((y / a - 1) / 2) * 3 + 2 + 2;
      }

      return -1;
    }
    return -1;
  }

  return -1;
}

int main() {
  ll a, x, y;
  cin >> a >> x >> y;

  cout << solve(a, x, y) << endl;

  return 0;
}
