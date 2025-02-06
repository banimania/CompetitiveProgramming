#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

const ll MOD = 1e9 + 7;

#define TESTCASES false

bool posible(vector<int> &p, int paradas, int tiempo) {
  int paradasActuales = 0;
  int tiempoActual = 0;

  REP (i, 0, p.size()) {
    tiempoActual += p[i];
    if (paradasActuales > paradas || tiempoActual > tiempo) {
      return false;
    } else if (i != p.size() - 1) {
      if (tiempoActual + p[i + 1] > tiempo) {
        paradasActuales++;
        tiempoActual = 0;
      }
    }
  }
  
  return paradasActuales <= paradas && tiempoActual <= tiempo;
}

int busquedaBinaria(vector<int> &p, int paradas) {
  int bajo = 0, alto = 0;
  REP (i, 0, p.size()) {
    alto += p[i];
  }

  while (alto > bajo) {
    int mitad = (alto - bajo) / 2 + bajo;

    if (posible(p, paradas, mitad)) alto = mitad - 1;
    else bajo = mitad + 1;
  }

  return alto;
}

void solve() {
  int n, paradas;
  while (cin >> n >> paradas) {
    vector<int> p(n);
    REP (i, 0, n) cin >> p[i];

    int ans = busquedaBinaria(p, paradas);
    while (!posible(p, paradas, ans)) ans++;
    cout << ans << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
