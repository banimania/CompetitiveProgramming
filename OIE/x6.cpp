#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    if (!n && !k) break;

    ll ans = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      q.push(x);

      while (x - q.front() >= k) {
        q.pop();
      }

      ans = max(ans, (ll) q.size());
    }

    cout << ans << "\n";
  }
  return 0;
}
