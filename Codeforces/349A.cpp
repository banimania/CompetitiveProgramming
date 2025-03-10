#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 0

void solve() {
  int n;
  cin >> n;

  int x, n25 = 0, n50 = 0;
  bool possible = true;
  for (int i = 0; i < n; i++) {
    cin >> x;

    if (possible) {
      if (x == 25) {
        n25++;
      } else if (x == 50) {
        if (n25) {
          n50++;
          n25--;
        } else {
          possible = false;
        }
      } else if (x == 100) {
        if (n50 && n25) {
          n50--;
          n25--;
        } else if (n25 >= 3) {
          n25 -= 3;
        } else {
          possible = false;
        }
      }
    }
  }

  cout << (possible ? "YES" : "NO") << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
