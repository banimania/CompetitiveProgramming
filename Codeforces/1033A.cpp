#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve() {
  int n;
  cin >> n;

  int ax, ay;
  cin >> ax >> ay;

  int bx, by;
  cin >> bx >> by;

  int cx, cy;
  cin >> cx >> cy;
  
  ax--, ay--, bx--, by--, cx--, cy--;

  /*cout << "a = (" << ax << ", " << ay << ")" << endl;
  cout << "b = (" << bx << ", " << by << ")" << endl;
  cout << "c = (" << cx << ", " << cy << ")" << endl;*/

  vector<bool> visitado(n * n, false);

  // Torre
  for (int i = 0; i < n; i++) {
    visitado[ay * n + i] = true;
    visitado[i * n + ax] = true;
  }

  // Alfil
  bool cont = true;
  int reina = ay * n + ax;
  for (int i = 0; i < n && cont; i++) {
    cont = false;

    if (n > ax + i && ax + i >= 0 && n > ay + i && ay + i >= 0) visitado[reina + (n * i) + i] = true, cont = true;
    if (n > ax - i && ax - i >= 0 && n > ay + i && ay + i >= 0) visitado[reina + (n * i) - i] = true, cont = true;
    if (n > ax + i && ax + i >= 0 && n > ay - i && ay - i >= 0) visitado[reina - (n * i) + i] = true, cont = true;
    if (n > ax - i && ax - i >= 0 && n > ay - i && ay - i >= 0) visitado[reina - (n * i) - i] = true, cont = true;
  }

  stack<int> pila;
  pila.push(by * n + bx);
  while (!pila.empty()) {
    int casilla = pila.top();
    int casx = casilla % n;
    int casy = casilla / n;

    if (casx == cx && casy == cy) {
      cout << "YES" << endl;
      return;
    }

    if (visitado[casilla]) {
      pila.pop();
      continue;
    }

    visitado[casilla] = true;

    // Arriba
    if (casy != 0 && !visitado[casilla - n]) {
      pila.push(casilla - n);
    }

    // Abajo
    if (casy != n - 1 && !visitado[casilla + n]) {
      pila.push(casilla + n);
    }

    // Izquierda
    if (casx != 0 && !visitado[casilla - 1]) {
      pila.push(casilla - 1);
    }

    // Derecha
    if (casx != n - 1 && !visitado[casilla + 1])  {
      pila.push(casilla + 1);;
    }

    // Arriba-derecha
    if (casx != n - 1 && casy != 0 && !visitado[casilla - n + 1]) {
      pila.push(casilla - n + 1);
    }
    
    // Arriba-izquierda
    if (casx != 0 && casy != 0 && !visitado[casilla - n - 1]) {
      pila.push(casilla - n - 1);
    }
    
    // Abajo-derecha
    if (casx != n - 1 && casy != n - 1 && !visitado[casilla + n + 1]) {
      pila.push(casilla + n + 1);
    }
    
    // Abajo-izquierda
    if (casx != 0 && casy != n - 1 && !visitado[casilla + n - 1]) {
      pila.push(casilla + n - 1);
    }
  }

  cout << "NO" << endl;

}

int main() {
  /*int t;
  cin >> t;
  while (t--) {
    solve();
  }*/
  solve();
}
