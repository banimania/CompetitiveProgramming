#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  while (cin >> n >> k) {
    if (!n && !k) break;

    ll curr = 0;
    ll ans = 0;
    int bestIndex = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      curr += x;
      q.push(x);

      while (q.size() > k) {
        curr -= q.front();
        q.pop();
      }

      if (curr >= ans) {
        ans = curr;
        bestIndex = i - (int) q.size() + 1;
      }
    }

    cout << bestIndex + 1 << " " << ans << "\n";
  }
  return 0;
}
