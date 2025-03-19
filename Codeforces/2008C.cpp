#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;

    int cnt = 0;

    int dif = 0;
    for (int i = l; i <= r; i += dif) {
      dif++;

      cnt++;
    }

    cout << cnt << endl;
  }
  return 0;
}
