#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int p, n;
  while (cin >> p >> n) {
    if (!p && !n) break;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    int ini = 0, fin = n - 1;

    int ans = 0;
    while (fin >= ini) {
      int suma = v[fin];
      fin--;

      if (suma + v[ini] <= p) {
        suma += v[ini];
        ini++;
      }

      ans++;
    }

    cout << ans << "\n";
  }
  return 0;
}
