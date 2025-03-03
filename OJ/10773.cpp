#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    double d, v, u;
    cin >> d >> v >> u;

    if (v == 0 || u == 0 || u <= v) {
      cout << "Case " << tt << ": can't determine" << endl;
      continue;
    }

    double t1 = d / u;
    double t2 = d / sqrt(u * u - v * v);
    
    double ans = abs(t2 - t1);

    cout << "Case " << tt << ": " << fixed << setprecision(3) << ans << endl;
  }
  return 0;
}
