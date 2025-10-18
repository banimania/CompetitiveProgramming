#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string line;
  while (getline(cin, line)) {
    line += "+";

    int i = 0;
    string ans = "";

    string coef = "";
    string grado = "";
    bool readCoef = true;

    bool ti = true;

    for (int i = 0; i < line.size(); i++) {
      if (isdigit(line[i])) {
        if (readCoef) {
          coef += line[i];
        } else {
          grado += line[i];
        }
      } else {
        if (line[i] == 'x') {
          ti = false;
        } else if (line[i] == '^') {
          readCoef = false;
        } else if (line[i] == '+') {
          if (ti) {

            if (ans.empty()) ans = "0";
            ti = true;
            readCoef = true;

            coef = "";
            grado = "";
            continue;
          }
          if (!ans.empty()) ans += "+";

          int coefInt = coef.empty() ? 1 : stoi(coef);
          int gradoInt = grado.empty() ? 1 : stoi(grado);

          int newGrado = gradoInt - 1;
          int newCoef = gradoInt * coefInt;

          ans += to_string(newCoef);
          if (newGrado > 0) {
            ans += "x";
          }
          if (newGrado > 1) {
            ans += "^";
            ans += to_string(newGrado);
          }
          ti = true;
          readCoef = true;
          coef = "";
          grado = "";
        }
      }
    }

    cout << ans << endl;
  }
  return 0;
}
