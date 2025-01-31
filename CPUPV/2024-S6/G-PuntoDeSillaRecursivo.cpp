#include <cctype>
#include <cmath>
#include <iostream>
#include <math.h>
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

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<vector<int>> matriz;

  REP (i, 0, n) {
    vector<int> fila(m);
    REP (j, 0, m) {
      cin >> fila[j];
    }
    matriz.push_back(fila);
  }

  vector<int> minFila;
  vector<int> maxColumna;
  REP (i, 0, m) {
    int max = 0;
    REP (j, 0, n) {
      max = fmax(matriz[j][i], max);
    }
    maxColumna.push_back(max);
  }
  REP (i, 0, n) {
    int min = 32769;
    REP (j, 0, m) {
      min = fmin(matriz[i][j], min);
    }
    minFila.push_back(min);
  }

  REP (i, 0, minFila.size()) {
    REP (j, 0, maxColumna.size()) {
      if (minFila[i] == maxColumna[j]) {
        cout << i << " " << j << endl;
        return;
      }
    }
  }

  cout << "-1 -1" << endl;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }
}
