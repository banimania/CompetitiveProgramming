#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, t;
  while (cin >> n >> t) {
    ll tot = n * n;
    vector<bool> fila(n);
    vector<bool> diag(2 * n - 1);

    for (int p = 0; p < t; p++) {
      ll i, j;
      cin >> i >> j;
      i--, j--;

      ll diagN = i - j + (n - 1);

      fila[i] = true;
      diag[diagN] = true;
      // cout << "FILA: " << i << "\n";
      // cout << "DIAG: " << diagN << "\n";
    }

    vector<ll> prefSum(n);
    for (int i = 0; i < n; i++) {
      prefSum[i] = (i > 0 ? prefSum[i - 1] : 0) + fila[i];
    }

    ll ans = n * n - prefSum[n - 1] * n;

    for (int d = 0; d < 2 * n - 1; d++) {
      if (diag[d]) {

        ll numFilas = n - abs(d - (n - 1));

        if (d == n - 1) {
          ll filasLibres = n - prefSum[n - 1];
          ans -= filasLibres;
        } else if (d > (n - 1)) {
          ll dist = d - (n - 1);

          ll filasLibres = numFilas - (prefSum[dist + numFilas - 1] - (dist - 1 >= 0 ? prefSum[dist - 1] : 0));
          ans -= filasLibres;
        } else {
          ll dist = (n - 1) - d;

          ll filasLibres = numFilas - (n - dist - 1 >= 0 ? prefSum[n - dist - 1] : 0); 
          ans -= filasLibres;
        }
        // cout << "diagonal = " << diagonal << " ocupa " << numFilas << endl;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
