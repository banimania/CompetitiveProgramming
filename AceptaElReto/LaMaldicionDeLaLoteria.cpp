#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    ll p, d, s, m;
    cin >> p >> d >> s >> m;

    ll max_sem = min(s, 7 * d);
    ll max_mes = min({m, 4 * max_sem, 28 * d});

    ll meses = p / max_mes;
    ll resto_mes = p % max_mes;

    ll semanas = resto_mes / max_sem;
    ll resto_sem = resto_mes % max_sem;

    ll dias = (resto_sem + d - 1) / d;

    cout << meses << " " << semanas << " " << dias << "\n";
  }


  return 0;
}
