#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (cin >> s && s != "0") {
    if (s.size() > 8) {
      while (s.size() < 13) {
        s = "0" + s;
      }
    } else {
      while (s.size() < 8) {
        s = "0" + s;
      }
    }

    int digControl = 0;
    bool imp = true;
    for (int i = s.size() - 2; i >= 0; i--) {
      digControl += (s[i] - '0') * (imp ? 3 : 1);
      imp = !imp;
    }
    digControl = (10 - (digControl % 10)) % 10;
    bool correcto = (digControl == (s[s.size() - 1] - '0'));
    cout << (correcto ? "SI" : "NO");

    if (correcto && s.size() == 13) {
      cout << " ";

      if (s[0] == '0') {
        cout << "EEUU";
      } else if (s[0] == '3' && s[1] == '8' && s[2] == '0') {
        cout << "Bulgaria";
      } else if (s[0] == '5' && s[1] == '0') {
        cout << "Inglaterra";
      } else if (s[0] == '5' && s[1] == '3' && s[2] == '9') {
        cout << "Irlanda";
      } else if (s[0] == '5' && s[1] == '6' && s[2] == '0') {
        cout << "Portugal";
      } else if (s[0] == '7' && s[1] == '0') {
        cout << "Noruega";
      } else if (s[0] == '7' && s[1] == '5' && s[2] == '9') {
        cout << "Venezuela";
      } else if (s[0] == '8' && s[1] == '5' && s[2] == '0') {
        cout << "Cuba";
      } else if (s[0] == '8' && s[1] == '9' && s[2] == '0') {
        cout << "India";
      } else {
        cout << "Desconocido";
      }
    }

    cout << endl;
  }
  return 0;
}
