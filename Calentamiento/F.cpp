#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool puedesMeter(vector<int> &juegos, int i, int suma1, int suma2, int tamCara) {
  if (i == juegos.size()) return true;
  int x = juegos[i];

  bool ans = false;
  if (suma1 + x <= tamCara) {
    ans |= puedesMeter(juegos, i + 1, suma1 + x, suma2, tamCara);
  }
  if (suma2 + x <= tamCara) {
    ans |= puedesMeter(juegos, i + 1, suma1, suma2 + x, tamCara);
  }

  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int tamCara, nJuegos;
  while (cin >> tamCara >> nJuegos) {
    vector<int> juegos(nJuegos);
    for (int i = 0; i < nJuegos; i++) {
      cin >> juegos[i];
    }

    bool ans = puedesMeter(juegos, 0, 0, 0, tamCara);

    cout << (ans ? "SI" : "NO") << "\n";
  }

  return 0;
}
