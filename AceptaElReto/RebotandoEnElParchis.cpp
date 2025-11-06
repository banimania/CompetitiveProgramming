#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  unsigned short n, curr, delta;
  while (cin >> n >> curr >> delta) {
    if (!n && !curr && !delta) break;

    unsigned short left = (curr - 1) * 2;
    unsigned short rightMid = (n - curr);
    unsigned short right = rightMid * 2;
    unsigned short newDelta = delta % (left + right);

    unsigned short ans = curr;

    if (newDelta > rightMid) {
      ans -= newDelta - right;
    } else {
      ans += newDelta;
    }
    cout << ans << "\n";
  }
  return 0;
}
