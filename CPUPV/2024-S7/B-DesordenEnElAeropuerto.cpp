#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<deque<char>> colas(3, deque<char>(n));
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      cin >> colas[i][j];
    }
  }
  
  string operacion;
  while (cin >> operacion) {
    if (operacion == "MOVER") {
      ll colaOrigen, colaDestino;
      cin >> colaOrigen >> colaDestino;

      if (colas[colaOrigen].empty()) continue;
      
      char persona = colas[colaOrigen].front();
      colas[colaOrigen].pop_front();
      colas[colaDestino].push_back(persona);
    } else if (operacion == "ATENDER") {
      ll cola;
      cin >> cola;

      if (colas[cola].empty()) continue;

      colas[cola].pop_front();
    } else if (operacion == "AGREGAR") {
      char persona;
      ll cola;
      cin >> persona >> cola;
      
      colas[cola].push_back(persona);
    }
  }

  for (int i = 0; i < 3; i++) {
    if (colas[i].empty()) {
      cout << "NO HAY NADIE" << endl;
    } else {
      for (char persona : colas[i]) {
        cout << persona << " ";
      }
      cout << endl;
    }
  }
}
