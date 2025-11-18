#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int panaderias;
  while (cin >> panaderias && panaderias) {
    vector<int> p(panaderias);
    for (int i = 0; i < panaderias; i++) {
      cin >> p[i];
    }

    int charcuterias;
    cin >> charcuterias;
    vector<int> c(charcuterias);
    for (int i = 0; i < charcuterias; i++) {
      cin >> c[i];
    }

    int ans = INT_MAX;

    int i = 0, j = 0;

    while (i < panaderias && j < charcuterias) {
      ans = min(ans, abs(p[i] - c[j]));

      if (p[i] > c[j]) {
        j++;
      } else {
        i++;
      }

    }

    cout << ans << "\n";
  }

  return 0;
}
