#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int x, n, m;
  cin >> x >> n >> m;

  n = min(n, 64);
  m = min(m, 64);

  ll mi = 0, ma = 0;

  ll aux = x;
  ll auxN = n, auxM = m;
  while (aux > 0 && auxN) {
    aux /= 2;
    auxN--;
  }
  while (aux > 0 && auxM) {
    aux = (aux + 1) / 2;
    auxM--;
  }
  ma = aux;

  aux = x;
  auxN = n, auxM = m;
  while (auxM > 0) {
    aux = (aux + 1) / 2;
    auxM--;
  }
  while (auxN > 0) {
    aux /= 2;
    auxN--;
  }
  mi = aux;

  cout << mi << " " << ma << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
