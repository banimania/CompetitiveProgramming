#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t, h;
  while (cin >> t >> h) {
    double grosor = t * 1e-6;

    int ans = 0;
    while (grosor <= h) {
      grosor *= 2;
      ans++;
    }

    cout << ans << "\n";
  }

  return 0;
}
