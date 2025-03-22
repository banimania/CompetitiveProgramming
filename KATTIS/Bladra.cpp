#include <bits/stdc++.h>
using namespace std;

int main() {
  int v, a, t;
  cin >> v >> a >> t;

  double ans = v * t + 0.5 * a * t * t;

  cout << fixed << setprecision(6) << ans << endl;

  return 0;
}
