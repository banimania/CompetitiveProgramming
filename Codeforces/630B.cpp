#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
  double n, t;
  cin >> n >> t;

  double ans = n * pow(1.000000011, t);
  cout << fixed << setprecision(6) << ans << endl;
}

int main() {
  solve();
  return 0;
}
