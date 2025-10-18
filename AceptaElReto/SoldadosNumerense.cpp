#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> romano = {
  {'I', 1},
  {'V', 5},
  {'X', 10},
  {'L', 50},
  {'C', 100},
  {'D', 500},
  {'M', 1000}
};

unordered_map<int, string> binario = {
  {1, "I"},
  {2, "II"},
  {3, "III"},
  {4, "IV"},
  {5, "V"},
  {6, "VI"},
  {7, "VII"},
  {8, "VIII"},
  {9, "IX"},
  {10, "X"},
  {20, "XX"},
  {30, "XXX"},
  {40, "XL"},
  {50, "L"},
  {60, "LX"},
  {70, "LXX"},
  {80, "LXXX"},
  {90, "XC"},
  {100, "C"},
  {200, "CC"},
  {300, "CCC"},
  {400, "CD"},
  {500, "D"},
  {600, "DC"},
  {700, "DCC"},
  {800, "DCCC"},
  {900, "CM"},
  {1000, "M"},
  {2000, "MM"},
  {3000, "MMM"},
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  while (cin >> str) {
    int num = 0;

    int restar = 0;

    for (int i = 0; i < str.size(); i++) {
      if (i == str.size() - 1) {
        num += romano[str[i]] - restar;
        break;
      }

      if (romano[str[i]] >= romano[str[i + 1]]) {
        num += romano[str[i]] - restar;
        restar = 0;
      } else {
        restar = romano[str[i]];
      }
    }

    num++;

    string romano = "";

    int millares = (num / 1000);
    int centenas = (num / 100) % 10;
    int decenas = (num / 10) % 10;
    int unidades = num % 10;

    if (millares > 0) {
      romano += binario[millares * 1000];
    }
    if (centenas > 0) {
      romano += binario[centenas * 100];
    }
    if (decenas > 0) {
      romano += binario[decenas * 10];
    }
    if (unidades > 0) {
      romano += binario[unidades];
    }
    cout << romano << "\n";
  }
  return 0;
}
