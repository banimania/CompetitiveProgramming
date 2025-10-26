#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, a;
    cin >> n >> a;

    a--;

    vector<int> regalos(n);
    for (int i = 0; i < n; i++) {
      cin >> regalos[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (i <= a) {
        ans += min(regalos[i], regalos[a]);
      } else {
        ans += min(regalos[i], regalos[a] - 1);
      }
    }

    ans *= 2;

    cout << ans << "\n";
  }

  return 0;
}
