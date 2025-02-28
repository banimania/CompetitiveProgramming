#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    if (s == "0") {
      cout << "COMPLETO" << endl;
      continue;
    }
    int ceros = 0;
    int suma = 0;
    for (int i = 0; i < s.size(); i++) {
      suma += s[i] - '0';
      if (s[i] == '0') ceros++;
    }

    int nextMult = 9 * ceil(suma / 9.0);

    int necesario = nextMult - suma;

    int cerosNecesarios = max(2 - ceros, 0);

    if (!cerosNecesarios && !necesario) {
      cout << "COMPLETO" << endl;
      continue;
    }
    for (int i = 0; i < cerosNecesarios; i++) {
      cout << 0;
    }
    if (necesario != 0) cout << necesario;
    cout << endl;
  }
  return 0;
}
