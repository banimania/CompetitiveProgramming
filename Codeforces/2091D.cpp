#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;

  int personasPorFila = ceil(k / (double) n);

  int sitiosLibres = m - personasPorFila;

  int grupos = sitiosLibres + 1;

  int maxGrupo = ceil(personasPorFila / (double) grupos);

  cout << maxGrupo << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
