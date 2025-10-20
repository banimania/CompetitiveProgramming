#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll x = 1;
    ll ma = LLONG_MIN, maV = 0, mi = LLONG_MAX, miV = 0;
    while (true) {
      cin >> x;

      if (!x) break;

      if (x > ma) {
        ma = x;
        maV = 1;
      } else if (x == ma) {
        maV++;
      }

      if (x < mi) {
        mi = x;
        miV = 1;
      } else if (x == mi) {
        miV++;
      }
    }

    cout << mi << " " << miV << " " << ma << " " << maV << "\n";
  }
  return 0;
}
