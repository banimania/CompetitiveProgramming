#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c) {
  return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}

int main() {
  int v;
  while (cin >> v && v) {
    cin.ignore();
    vector<string> finTodo(v), finVocales(v);

    string verso;
    for (int i = 0; i < v; i++) {
      getline(cin, verso);
      stringstream ss(verso);
      string palabra;
      while (ss >> palabra) {}
      verso = "";
      for (int j = 0; j < palabra.size(); j++) {
        if (isalpha(palabra[j])) {
          verso += tolower(palabra[j]);
        }
      }
      string todo = "", vocales = "";
      bool seenVowel = false;
      int k = 0;
      for (int j = verso.size() - 1; j >= 0; j--) {

        if (isvowel(verso[j])) {
          if (!seenVowel) {
            seenVowel = true;
          } else {
            k = j;
            break;
          }
        }
      }
      for (int j = k; j < verso.size(); j++) {
        if (isvowel(verso[j])) {
          vocales += verso[j];
        }
        todo += verso[j];
      }

      finTodo[i] = todo;
      finVocales[i] = vocales;

      // cout << todo << endl;
      // cout << vocales << endl;
    }

    string ans = "DESCONOCIDO";
    if (v == 2) {
      if (finTodo[0] == finTodo[1]) {
        ans = "PAREADO";
      }
    } else if (v == 3) {
      if (finTodo[0] == finTodo[2] && finTodo[0] != finTodo[1]) {
        ans = "TERCETO";
      }
    } else if (v == 4) {
      if (finTodo[0] == finTodo[3] && finTodo[1] == finTodo[2] && finTodo[0] != finTodo[1]) {
        ans = "CUARTETO";
      } else if (finTodo[0] == finTodo[2] && finTodo[1] == finTodo[3] && finTodo[0] != finTodo[1]) {
        ans = "CUARTETA";
      } else if (finVocales[1] == finVocales[3] && finVocales[0] != finVocales[1] && finVocales[1] != finVocales[2] && finVocales[0] != finVocales[2]) {
        ans = "SEGUIDILLA";
      } else if (finTodo[0] == finTodo[1] && finTodo[1] == finTodo[2] && finTodo[2] == finTodo[3]) {
        ans = "CUADERNA VIA";
      }

    }

    cout << ans << '\n';
  }
  return 0;
}
