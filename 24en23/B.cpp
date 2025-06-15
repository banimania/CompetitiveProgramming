#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 0

void solve() {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;

    cin.ignore();

    vector<string> inp(n);
    vector<string> actual(n), deseada(n);
    for (int i = 0; i < n; i++) {
      getline(cin, inp[i]);
    }

    for (int i = 0; i < n; i++) {
      int it = inp[i].find(" ");

      actual[i] = inp[i].substr(0, it);
      deseada[i] = inp[i].substr(it + 1);
    }

    int ans = 0;
    int encendidos = 0, apagados = 0, error = 0;
    int encendidosD = 0, apagadosD = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (actual[i][j] == 'R') {
          error++;
        } else if (actual[i][j] == '1') {
          encendidos++;
        } else if (actual[i][j] == '0') {
          apagados++;
        }

        if (deseada[i][j] == '1') {
          encendidosD++;
        } else if (deseada[i][j] == '0') {
          apagadosD++;
        }
      }
    }

    int apagarManual = 0;
    if (encendidos > encendidosD) {
      apagarManual = encendidos - encendidosD;
      ans += apagarManual;
      apagados += apagarManual;
      encendidos -= apagarManual;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (actual[i][j] == '1' && deseada[i][j] == '0') {
          if (apagarManual) {
            apagarManual--;
            actual[i][j] = '0';
          }
        }
      }
    }

    if (encendidosD > encendidos + error) {
      cout << "IMPOSIBLE" << endl;
      continue;
    }

    int encenderConError = encendidosD - encendidos;
    encendidos += encenderConError;
    error -= encenderConError;
    ans += encenderConError;

    int apagarConError = error;
    apagados += apagarConError;
    error -= apagarConError;
    ans += apagarConError;

    if (encendidosD != encendidos || apagadosD != apagados) {
      cout << "IMPOSIBLE" << endl;
      continue;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (actual[i][j] == 'R') {
          if (encenderConError && deseada[i][j] == '1') {
            encenderConError--;
            actual[i][j] = '1';
          } else if (apagarConError && deseada[i][j] == '0') {
            apagarConError--;
            actual[i][j] = '0';
          } else {
            if (encenderConError) {
              encenderConError--;
              actual[i][j] = '1';
            } else {
              apagarConError--;
              actual[i][j] = '0';
            }
          }
        }
      }
    }

    int mismatch = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (actual[i][j] != deseada[i][j]) {
          mismatch++;
        }
      }
    }

    ans += mismatch / 2;

    cout << ans << endl;
  }
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) solve();
  return 0;
}
