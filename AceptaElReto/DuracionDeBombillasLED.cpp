#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    ll h, e, hEst;
    cin >> h >> e >> hEst;

    long double frac = (long double) h / hEst;

    if (frac < e) {
      cout << "HORAS\n";
    } else if (frac > e) {
      cout << "ENCENDIDOS\n";
    } else {
      cout << "AMBAS\n";
    }

  }

  return 0;
}
