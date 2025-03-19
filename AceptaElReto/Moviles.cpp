#include <bits/stdc++.h>
using namespace std;

pair<int, int> movilBalanceado() {
  int pi, di, pd, dd;
  cin >> pi >> di >> pd >> dd;

  if (!pi && !di && !pd && !dd) {
    return {-1, -1};
  }

  bool balanceado = true;

  if (!pi) {
    pair<int, int> x = movilBalanceado();
    balanceado = (balanceado && x.second);
    pi = x.first;
  }
  
  if (!pd) {
    pair<int, int> x = movilBalanceado();
    balanceado = (balanceado && x.second);
    pd = x.first;
  }

  int peso = pi + pd;

  balanceado = (balanceado && (pi * di == pd * dd));

  return {peso, balanceado};

}

int main() {
  pair<int, int> res;
  while ((res = movilBalanceado()).first != -1) {
    cout << (res.second == 1 ? "SI" : "NO") << endl;
  }
  return 0;
}
