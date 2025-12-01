#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    queue<int> q;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      q.push(x);

      while (x - q.front() >= 100) {
        q.pop();
      }

      ans = max(ans, (int) q.size());
    }

    cout << ans << "\n";
  }
  return 0;
}
