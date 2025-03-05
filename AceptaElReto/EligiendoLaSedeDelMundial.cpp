#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    map<string, int> votos;

    int maxVotos = 0;
    string ganador = "EMPATE";
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      votos[s]++;

      if (votos[s] > maxVotos) {
        maxVotos = votos[s];
        ganador = s;
      } else if (votos[s] == maxVotos) {
        ganador = "EMPATE";
      }
    }

    cout << ganador << endl;
  }
  return 0;
}
