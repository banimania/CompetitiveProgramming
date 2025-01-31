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

#define TESTCASES true

// bool works(ll px, ll py, ll ax, ll ay, ll bx, ll by, double w) {
//   if (w >= sqrt(pow(px, 2) + pow(py, 2))) return true;
//   else {
//     if (w >= sqrt(pow(px - ax, 2) + pow(py - ay, 2))
//     || w >= sqrt(pow(px - bx, 2) + pow(py - by, 2))) {
//       if (w * 2.0f >= sqrt(pow(ax - bx, 2) + pow(ay - by, 2))) return true;
//     }
//   }
//   return false;
// }

// bool works(ll px, ll py, ll ax, ll ay, ll bx, ll by, double w) {
//   if (!(w >= sqrt(pow(ax, 2) + pow(ay, 2))) && !(w >= sqrt(pow(bx, 2) + pow(by, 2)))) return false;

//   if (w >= sqrt(pow(px, 2) + pow(py, 2))) return true;
//   if (w >= sqrt(pow(px - ax, 2) + pow(py - ay, 2)) || w >= sqrt(pow(px - bx, 2) + pow(py - by, 2))) {
//     if (w * 2.0f >= sqrt(pow(ax - bx, 2) + pow(ay - by, 2))) return true;
//   }
//   return false;
// }

bool works(ll px, ll py, ll ax, ll ay, ll bx, ll by, double w) {
  bool pDentroA = w >= sqrt(pow(px - ax, 2) + pow(py - ay, 2)); 
  bool pDentroB = w >= sqrt(pow(px - bx, 2) + pow(py - by, 2)); 

  if (pDentroA || pDentroB) { // P dentro de alguna esfera
    bool oDentroA = w >= sqrt(pow(ax, 2) + pow(ay, 2));
    bool oDentroB = w >= sqrt(pow(bx, 2) + pow(by, 2));

    if (oDentroA || oDentroB) {
      if ((oDentroA && pDentroA) || (oDentroB && pDentroB)) return true;
      if (w * 2.0f >= sqrt(pow(ax - bx, 2) + pow(ay - by, 2))) return true; // a y b tangentes o se solapan
    }
  }

  return false;
}

void solve() {
  ll px, py, ax, ay, bx, by;
  cin >> px >> py >> ax >> ay >> bx >> by;

  double bajo = 0;
  double alto = 999999999;

  while (alto > bajo) {
    double medio = (alto - bajo) / 2.0f + bajo;

    if (works(px, py, ax, ay, bx, by, medio)) alto = medio - 1e-10;
    else bajo = medio + 1e-10;
  }

  cout << fixed << setprecision(10) << alto << endl;
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
