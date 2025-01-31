#include <cctype>
#include <cmath>
#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
 
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))
 
int main() {
  ll w, h;
  cin >> w >> h;

  vector<char> laberinto;
  
  int entrada = 0;
  int salida = 0;

  REP (i, 0, h) {
    string s;
    cin >> s;
    REP (j, 0, w) {
      if (s[j] == 'E') entrada = i * w + j;
      if (s[j] == 'S') salida = i * w + j;
      laberinto.push_back(s[j]);
    }
  }


  int casillas = 1;

  stack<int> pila;
  vector<int> prev(w * h, -1);
  vector<bool> visitadas(w * h, false);
  pila.push(entrada);
  while (!pila.empty()) {
    int celda = pila.top();
    if (celda == salida) break;

    if (visitadas[celda]) {
      pila.pop();
      continue;
    }

    visitadas[celda] = true;
    
    // IZQUIERDA
    if (celda % w != 0 && laberinto[celda - 1] != '#' && !visitadas[celda - 1]) pila.push(celda - 1), prev[celda - 1] = celda;
    // DERECHA
    if (celda % w != w - 1 && laberinto[celda + 1] != '#' && !visitadas[celda + 1]) pila.push(celda + 1), prev[celda + 1] = celda;
    // ARRIBA
    if (celda / w != 0 && laberinto[celda - w] != '#' && !visitadas[celda - w]) pila.push(celda - w), prev[celda - w] = celda;
    // ABAJO
    if (celda / w != h - 1 && laberinto[celda + w] != '#' && !visitadas[celda + w]) pila.push(celda + w), prev[celda + w] = celda;
  }

  while (prev[salida] != -1) {
    salida = prev[salida];
    casillas++;
  }
  cout << casillas << endl;
}
