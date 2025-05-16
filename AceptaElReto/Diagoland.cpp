#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m, n, cnt;
  float ans;
  char x;
  while (cin >> m >> n) {
    if (!m && !n) break;

    ans = 0;

    for (int i = 0; i < n; i++) {
      cnt = 0;
      for (int j = 0; j < m; j++) {
        cin >> x;

        if (x == '\\' || x == '/') {
          ans += 0.5;
          cnt++;
        } else if (cnt % 2) ans++;
      }
    }
    cout << ans << endl;
  }
}
