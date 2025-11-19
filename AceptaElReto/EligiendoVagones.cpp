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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];


    int ini = 0, fin = -1;
    for (int i = 0; i < n; i++) {
      fin++;

      curr += v[i];

      while (curr >= p) {
        int vagones = (fin - ini + 1);

        if (vagones < ans) {
          ans = vagones;
          idx = ini;
        }

        curr -= v[ini];
        ini++;
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
