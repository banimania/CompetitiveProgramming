#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool solve(int i, vector<vector<int>> &posicionesP1, vector<vector<int>> &posicionesP2, vector<vector<int>> &posicionesP3, char simb, int &n1, int &n2, int &n3, int n, vector<bool> &used, string &p1, string &p2, string &p3, unordered_map<char, int> &idLetra, vector<int> &pot, vector<int> &valP1, vector<int> &valP2, vector<int> &valP3) {
  if (i == n) {
    if (simb == '+') {
      if (n1 + n2 == n3) {
        cout << n1 << " + " << n2 << " = " << n3 << "\n";
        return true;
      }
    } else {
      if ((ll) n1 * n2 == (ll) n3) {
        cout << n1 << " * " << n2 << " = " << n3 << "\n";
        return true;
      }
    }
    return false;
  }

  int start = (idLetra[p1[0]] == i || idLetra[p2[0]] == i || idLetra[p3[0]] == i) ? 1 : 0;
  for (int x = start; x <= 9; x++) {
    if (used[x]) continue;

    int n1Add = x * valP1[i], n2Add = x * valP2[i], n3Add = x * valP3[i];

    n1 += n1Add;
    n2 += n2Add;
    n3 += n3Add;
    used[x] = true;

    if (solve(i + 1, posicionesP1, posicionesP2, posicionesP3, simb, n1, n2, n3, n, used, p1, p2, p3, idLetra, pot, valP1, valP2, valP3)) return true;

    used[x] = false;
    n3 -= n3Add;
    n2 -= n2Add;
    n1 -= n1Add;
  }

  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  char simb, eq;
  string p1, p2, p3;
  while (cin >> p1 >> simb >> p2 >> eq >> p3) {
    unordered_map<char, int> idLetra;
    int cnt = 0;
    for (int i = 0; i < p1.size(); i++) {
      if (!idLetra.count(p1[i])) {
        idLetra[p1[i]] = cnt;
        cnt++;
      }
    }
    for (int i = 0; i < p2.size(); i++) {
      if (!idLetra.count(p2[i])) {
        idLetra[p2[i]] = cnt;
        cnt++;
      }
    }
    for (int i = 0; i < p3.size(); i++) {
      if (!idLetra.count(p3[i])) {
        idLetra[p3[i]] = cnt;
        cnt++;
      }
    }

    vector<vector<int>> posicionesP1(idLetra.size()), posicionesP2(idLetra.size()), posicionesP3(idLetra.size());
    for (int i = 0; i < p1.size(); i++) {
      posicionesP1[idLetra[p1[i]]].push_back(i);
    }
    for (int i = 0; i < p2.size(); i++) {
      posicionesP2[idLetra[p2[i]]].push_back(i);
    }
    for (int i = 0; i < p3.size(); i++) {
      posicionesP3[idLetra[p3[i]]].push_back(i);
    }

    int n = idLetra.size();

    vector<int> pot(10);
    pot[0] = 1;
    for (int i = 1; i <= 9; i++) pot[i] = 10 * pot[i - 1];

    int n1 = 0, n2 = 0, n3 = 0;
    vector<bool> used(10);

    vector<int> valP1(n, 0), valP2(n, 0), valP3(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < posicionesP1[i].size(); j++) {
        valP1[i] += pot[p1.size() - 1 - posicionesP1[i][j]];
      }
      for (int j = 0; j < posicionesP2[i].size(); j++) {
        valP2[i] += pot[p2.size() - 1 - posicionesP2[i][j]];
      }
      for (int j = 0; j < posicionesP3[i].size(); j++) {
        valP3[i] += pot[p3.size() - 1 - posicionesP3[i][j]];
      }
    }
    solve(0, posicionesP1, posicionesP2, posicionesP3, simb, n1, n2, n3, n, used, p1, p2, p3, idLetra, pot, valP1, valP2, valP3);
  }
  return 0;
}
