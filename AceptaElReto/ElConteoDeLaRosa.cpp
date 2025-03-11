#include <bits/stdc++.h>
using namespace std;

int contarDigitos(int inicio, int final) {
  int p = log10(inicio) + 1;
  int p2 = log10(final) + 1;

  int cnt = 0;

  for (int i = p; i <= p2; i++) {
    int minRelativo = pow(10, i - 1);
    int maxRelativo = pow(10, i) - 1;

    if (i == p && i == p2) {
      minRelativo = inicio;
      maxRelativo = final;
    } else if (i == p) {
      minRelativo = inicio;
    } else if (i == p2) {
      maxRelativo = final;
    }

    int nums = maxRelativo - minRelativo + 1;
    cnt += nums * i;
  }

  return cnt;
}

int main() {
  int inicio, final;
  while (cin >> inicio >> final) {
    if (!inicio && !final) break;

    int alto = final;
    int bajo = inicio;

    int medio;

    while (alto >= bajo) {
      medio = (alto - bajo) / 2 + bajo;

      int int1 = contarDigitos(inicio, medio);
      int int2 = contarDigitos(medio + 1, final);

      if (int1 > int2) {
        alto = medio - 1;
      } else if (int1 < int2) {
        bajo = medio + 1;
      } else {
        break;
      }
    }
    int int1 = contarDigitos(inicio, medio);
    int int2 = contarDigitos(medio + 1, final);
    cout << (int1 > int2 ? medio - 1 : medio) << endl;
  }
  return 0;
}
