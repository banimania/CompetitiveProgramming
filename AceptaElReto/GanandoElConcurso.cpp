#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n, t;
  while (cin >> n >> t) {
    if (!n && !t) break;

    vector<int> tiempos(n);
    for (int i = 0; i < n; i++) {
      cin >> tiempos[i];
    }
    sort(tiempos.begin(), tiempos.end());

    int currT = 0;
    int ans = 0;
    int pen = 0;
    for (int i = 0; i < n; i++) {
      currT += tiempos[i];
      if (currT <= t) {
        pen += currT;
        ans++;
      } else break;
    }

    cout << ans << " " << pen << "\n";
  }
  return 0;
}
