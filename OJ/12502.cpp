#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    double x, y, z;
    cin >> x >> y >> z;

    double r = z / (x + y);
    double ans = x * r + (x - y) * r;
    cout << round(ans) << endl;
  }
  return 0;
}
