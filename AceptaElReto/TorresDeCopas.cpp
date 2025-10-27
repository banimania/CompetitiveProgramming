#include <bits/stdc++.h>
using namespace std;

int copasLlenas(int niv, int imp, int par, int liq) {
  vector<vector<double>> copas(niv);
  for (int i = 0; i < niv; i++) {
    for (int j = 0; j <= i; j++) {
      copas[i].push_back(0.0);
    }
  }

  copas[0][0] += liq;
  for (int i = 0; i < niv - 1; i++) {
    for (int j = 0; j <= i; j++) {
      double necesita = (i % 2 ? par : imp);
      if (copas[i][j] > necesita) {
        double sobra = copas[i][j] - necesita;

        copas[i][j] = necesita;
        copas[i + 1][j] += sobra / 2.0;
        copas[i + 1][j + 1] += sobra / 2.0;
      }
    }
  }

  int copasLlenas = 0;

  for (int i = 0; i < niv; i++) {
    for (int j = 0; j <= i; j++) {
      double necesita = (i % 2 ? par : imp);

      if (copas[i][j] >= necesita) {
        copasLlenas++;
      }
    }
  }

  return copasLlenas;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int niv, imp, par, b, inv;
  while (cin >> niv >> imp >> par >> b >> inv) {
    int low = 1, high = 1000000000;

    int liq = 0;
    while (high >= low) {
      int mid = (high - low) / 2 + low;

      if (copasLlenas(niv, imp, par, mid) >= inv) {
        high = mid - 1;
        liq = mid;
      } else {
        low = mid + 1;
      }

    }

    int botellas = ceil(liq / (double) b);
    cout << botellas << endl;
  }
  return 0;
}
