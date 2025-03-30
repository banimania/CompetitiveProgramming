#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    int ans = 0;
    if (n <= 1) ans = 1;
    else if (n == 2) ans = 2;
    else if (n == 3) ans = 6;
    else if (n == 4) ans = 4;

    cout << ans << endl;
  }
  return 0;
}
