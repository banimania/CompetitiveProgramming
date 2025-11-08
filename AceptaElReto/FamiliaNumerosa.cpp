#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll c, n;
    cin >> c >> n;

    ll a = (n * c) / (c - 1);

    if ((a * (c - 1)) % c == 0) {
      cout << a - 1 << " " << a << "\n";
    } else {
      cout << a << " " << a << "\n";
    }
  }
  return 0;
}
