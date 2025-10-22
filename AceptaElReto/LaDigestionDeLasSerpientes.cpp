#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    if (!n && !k) break;

    int ans = 0;
    bool started = false;
    int currLength = 0;
    int currBK = 0;

    for (int i = 0; i < n; i++) {
      bool x;
      cin >> x;

      if (x) {
        if (!started) {
          started = true;
        }
        currLength++;
        currBK = 0;
        ans = max(ans, currLength);
      } else {
        if (started) {
          currBK++;
          if (currBK > k) {
            currBK = 0;
            started = false;
            currLength = 0;
          } else {
            currLength++;
          }
        }
      }

    }

    cout << ans << "\n";
  }
  return 0;
}
