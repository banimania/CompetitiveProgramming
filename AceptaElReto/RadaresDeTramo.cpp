#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll d, vmax, t;
  while (cin >> d >> vmax >> t) {
    if (!d && !vmax && !t) break;

    if (d <= 0 || vmax <= 0 || t <= 0) {
      cout << "ERROR\n";
      continue;
    }

    ld vmedia = 3.6 * ((double) d / t);

    if (vmedia <= vmax) {
      cout << "OK\n";
    } else if (vmedia < 1.2 * vmax) {
      cout << "MULTA\n";
    } else {
      cout << "PUNTOS\n";
    }

  }
  return 0;
}
