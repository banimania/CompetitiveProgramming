#include <bits/stdc++.h>
using namespace std;

vector<string> dias = {"MARTES", "MIERCOLES", "JUEVES", "VIERNES", "SABADO", "DOMINGO"};

int main() {
  while (true) {
    float inp, suma = 0;
    int i = 0;
    float mi = numeric_limits<float>::max(), ma = numeric_limits<float>::lowest();
    int mejor = -1, peor = -1;
    bool empateMejor = false, empatePeor = false;
    vector<float> ventas;

    cin >> inp;
    if (inp == -1) break;

    ventas.push_back(inp);
    suma += inp;
    mi = ma = inp;
    mejor = peor = 0;

    for (i = 1; i < 6; i++) {
      cin >> inp;
      ventas.push_back(inp);
      suma += inp;

      if (inp > ma) {
        ma = inp;
        mejor = i;
        empateMejor = false;
      } else if (inp == ma) {
        empateMejor = true;
      }

      if (inp < mi) {
        mi = inp;
        peor = i;
        empatePeor = false;
      } else if (inp == mi) {
        empatePeor = true;
      }
    }

    float media = suma / 6;
    cout << (empateMejor ? "EMPATE" : dias[mejor]) << " " << (empatePeor ? "EMPATE" : dias[peor]) << " " << (ventas[5] > media ? "SI" : "NO") << endl;
  }

  return 0;
}
