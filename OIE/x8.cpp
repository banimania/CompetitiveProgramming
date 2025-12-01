#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int p, n;
  while (cin >> p >> n) {
    if (!p && !n) break;

    int ans = INT_MAX;
    int idx = 0;

    int curr = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      q.push(x);

      curr += x;

      while (curr >= p) {
        int vagones = (int) q.size();

        if (vagones < ans) {
          ans = vagones;
          idx = i - vagones + 1;
        }

        curr -= q.front();
        q.pop();
      }

    }

    if (ans == INT_MAX) {
      cout << "NO ENTRAN\n";
    } else {
      cout << ans << " " << idx + 1 << "\n";
    }
  }
  return 0;
}
