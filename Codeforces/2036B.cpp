#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a, n) for (int i = 0; i < n; ++i) cin >> a[i]
#define PRINT(a, n) for (int i = 0; i < n; ++i) { cout << a[i] << " "; }
#define PRINTLN(a, n) for (int i = 0; i < n; ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a, n) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a, n) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, n, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, n, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, n, target) lower_bound(a.begin(), a.end(), target) - a.begin()

/*void solve() {
  ll n, k;
  cin >> n >> k;

  vll b(k);
  vll c(k);

  REP (i, 0, k) {
    cin >> b[i] >> c[i];
  }

  vll bord(k);
  REP (i, 0, k) {
    bord[i] = b[i];
  }
  sort(bord.begin(), bord.end(), [k, bord, c](int x, int y) {
    int sumaX = 0;
    int sumaY = 0;
    REP (i, 0, k) {
      if (bord[i] == x) sumaX += c[i];
      else if (bord[i] == y) sumaY += c[i];
    }

    return sumaX > sumaY;
  });

  bord.erase(unique(bord.begin(), bord.end()), bord.end());
  int total = 0;
  int marca = -1;
  //cout << "ITERANDO " << min((int) n, (int) bord.size()) << endl;
  REP (i, 0, min((int)n, (int)bord.size())) {
    //if (marca == bord[i]) continue;
    marca = bord[i];
    REP (j, 0, k) {
      if (b[j] == marca) {
        total += c[j];
        //cout << "AÑADIDA BOTELLA DE MARCA " << marca << " DE COSTE " << c[j] << endl;
      }
    }
  }

  cout << total << endl;
}*/

void solve() {
  ll n, k;
  cin >> n >> k; //N = ESTANTERIAS ; K = N BOTELLAS

  vector<ll> precioMarca(k);

  REP (i, 0, k) precioMarca[i] = 0;

  REP (i, 0, k) {
    ll marca = 0, coste = 0;
    cin >> marca >> coste;
    precioMarca[marca - 1] += coste;
  }

  sort(precioMarca.begin(), precioMarca.end(), [](ll a, ll b) {
    return a > b;
  });

  
  ll costo = 0;

  REP (i, 0, min((int)n, (int)precioMarca.size())) {
    costo += precioMarca[i];
  }
  cout << costo << endl;
}

int main() {
  ll t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
