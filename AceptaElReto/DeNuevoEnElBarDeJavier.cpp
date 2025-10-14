#include <bits/stdc++.h>
using namespace std;

unordered_map<char, string> catName = {
  {'D', "DESAYUNOS"},
  {'A', "COMIDAS"},
  {'M', "MERIENDAS"},
  {'I', "CENAS"},
  {'C', "COPAS"},
};

string catMax(unordered_map<char, double> &beneficios) {
  string ans = "EMPATE";
  double cMax = DBL_MIN;
  bool empate = true;
  for (const pair<char, double> &p : beneficios) {
    if (p.second > cMax) {
      cMax = p.second;
      ans = catName[p.first];
      empate = false;
    } else if (p.second == cMax) {
      empate = true;
    }
  }

  return (empate ? "EMPATE" : ans);
}

string catMin(unordered_map<char, double> &beneficios) {
  string ans = "EMPATE";
  double cMin = DBL_MAX;
  bool empate = true;
  for (const pair<char, double> &p : beneficios) {
    if (p.second < cMin) {
      cMin = p.second;
      ans = catName[p.first];
      empate = false;
    } else if (p.second == cMin) {
      empate = true;
    }
  }

  return (empate ? "EMPATE" : ans);
}

int main() {
  char c;
  double v;

  unordered_map<char, double> beneficios = {
    {'D', 0},
    {'A', 0}, 
    {'M', 0},
    {'I', 0},
    {'C', 0},
  };
  double nvA = 0;
  double nv = 0;
  double totalComidas = 0;
  double total = 0;
  while (cin >> c >> v) {
    if (c == 'N' && v == 0) {
      double mediaDia = (nv > 0 ? total / nv : 0);
      double mediaComidas = (nvA > 0 ? totalComidas / nvA : 0);

      cout << catMax(beneficios) << "#" << catMin(beneficios) << "#" << (mediaComidas > mediaDia ? "SI" : "NO") << '\n';
      beneficios = {
        {'D', 0},
        {'A', 0}, 
        {'M', 0},
        {'I', 0},
        {'C', 0},
      };

      nv = 0;
      nvA = 0;
      total = 0;
      totalComidas = 0;
      continue;
    }

    beneficios[c] += v;
    if (c == 'A') {
      nvA++;
      totalComidas += v;
    }
    nv++;
    total += v;
  }
  return 0;
}
