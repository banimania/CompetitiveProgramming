#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  double ans = 0;

  for (int i = 0; i < n; i++) {
    double a, b;
    cin >> a >> b;

    ans += a * b;
  }

  cout << fixed << setprecision(3) << ans << endl;

  return 0;
}
