#include <bits/stdc++.h>
using namespace std;

map<string, int> notas = {
  {"Do", 0},
  {"Si#", 0},
  {"Do#", 1},
  {"Reb", 1},
  {"Re", 2},
  {"Re#", 3},
  {"Mib", 3},
  {"Mi", 4},
  {"Fab", 4},
  {"Fa", 5},
  {"Mi#", 5},
  {"Fa#", 6},
  {"Solb", 6},
  {"Sol", 7},
  {"Sol#", 8},
  {"Lab", 8},
  {"La", 9},
  {"La#", 10},
  {"Sib", 10},
  {"Dob", 11},
  {"Si", 11}
};

int main() {
  int n;
  while (cin >> n && n) {
    map<int, int> freq;
    int hp = INT_MIN, lp = INT_MAX;

    for (int i = 0; i < n; i++) {
      string nota;
      cin >> nota;

      int octava = nota[nota.size() - 1] - '0';
      string notaR = nota.substr(0, nota.size() - 1);

      int notaVal = notas[notaR] + (octava - 1) * 12;
      if (notaR == "Dob") {
        notaVal = notas[notaR] + (octava - 2) * 12;
      } else if (notaR == "Si#") {
        notaVal = notas[notaR] + (octava) * 12;
      }

      freq[notaVal]++;
      hp = max(hp, notaVal);
      lp = min(lp, notaVal);
    }


    for (int i = lp; i <= hp; i++) {
      cout << freq[i] << (i == hp ? "" : " ");
    }
    cout << endl;
  }
  return 0;
}
