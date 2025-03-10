#include <bits/stdc++.h>
using namespace std;

int main() {
  int litros, barr, perd, litrosV, barrV, perdV;
  while (cin >> litros >> barr >> perd >> litrosV >> barrV >> perdV) {
    if (!litros || !litrosV) break;

    int viajes = ceil((litros - barr) / (double)(barr - perd)) + 1;
    int viajesV = ceil((litrosV - barrV) / (double)(barrV - perdV)) + 1;

    if (barr > litros) viajes = 1;
    if (barrV > litrosV) viajesV = 1;

    if (perd >= barr) {
      if (barr >= litros) viajes = 1;
      else viajes = INT_MAX;
    }

    if (perdV >= barrV) {
      if (barrV >= litrosV) viajesV = 1;
      else viajesV = INT_MAX;
    }

    if (viajes == viajesV) {
      cout << "EMPATE " << viajes << endl;
    } else if (viajes > viajesV) {
      cout << "VECINO " << viajesV << endl;
    } else {
      cout << "YO " << viajes << endl;
    }
  }
  return 0;
}
