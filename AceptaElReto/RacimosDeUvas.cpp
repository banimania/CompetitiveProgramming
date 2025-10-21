#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    int ans = ceil((-1 + sqrt(1 + 8 * n)) / 2.0);

    cout << ans << "\n";
  }

  return 0;
}
