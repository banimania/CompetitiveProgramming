#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int g = 0, n = 0;
  string token;
  while (cin >> token) {

    if (token == ".") {
      if (!g && !n) break;

      bool sobraGris = g % 2;
      bool sobraNegro = n % 2;

      if (sobraGris && sobraNegro) {
        cout << "PAREJA MIXTA\n";
      } else if (sobraGris) {
        cout << "GRIS SOLITARIO\n";
      } else if (sobraNegro) {
        cout << "NEGRO SOLITARIO\n";
      } else {
        cout << "EMPAREJADOS\n";
      }
      g = 0;
      n = 0;
    } else if (token == "G") {
      g++;
    } else {
      n++;
    }
  }
  return 0;
}
