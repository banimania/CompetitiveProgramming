#include <bits/stdc++.h>
using namespace std;

int main() {
  map<char, double> ventas = {{'D', 0}, {'A', 0}, {'M', 0}, {'I', 0}, {'C', 0}};
  map<char, string> nombres = {{'D', "DESAYUNOS"}, {'A', "COMIDAS"}, {'M', "MERIENDAS"}, {'I', "CENAS"}, {'C', "COPAS"}};
  char x;
  double v;
  while (cin >> x >> v) {
    if (x == 'N') {
      string maxVentas = "EMPATE", minVentas = "EMPATE";
      double maxVentasV = -1, minVentasV = DBL_MAX;

      double media = 0.0f;
      int cats = 0;
      for (pair<char, double> venta : ventas) {
        media += venta.second;
        if (venta.second > 0.0f) cats++;

        if (venta.second > maxVentasV) {
          maxVentasV = venta.second;
          maxVentas = nombres[venta.first];
        } else if (venta.second == maxVentasV) {
          maxVentas = "EMPATE";
        }
        
        if (venta.second < minVentasV) {
          minVentasV = venta.second;
          minVentas = nombres[venta.first];
        } else if (venta.second == minVentasV) {
          minVentas = "EMPATE";
        }
      }

      if (cats > 0) media /= cats;

      cout << maxVentas << "#" << minVentas << "#" << (ventas['A'] > media ? "SI" : "NO") << endl;

      ventas = {{'D', 0}, {'A', 0}, {'M', 0}, {'I', 0}, {'C', 0}};
    } else {
      ventas[x] += v;
    }
  }
  return 0;
}
