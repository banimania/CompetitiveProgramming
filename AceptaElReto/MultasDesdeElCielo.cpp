#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    cout << (b > c && d > a ? "SOLAPADOS\n" : "SEPARADOS\n");
  }
  return 0;
}
