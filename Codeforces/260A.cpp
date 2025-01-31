#include <cctype>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](int x, int y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](int x, int y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))
#define MOD 1e9 + 7

// estaba muy feliz con esta solución :(
// pero me acabo de dar cuenta de que
// se puede poner el primer dígito y luego todo ceros
// y ya lo haces con strings xd (además de que n puede ser 10e5)
//
// si estás leyendo esto, qué haces con tu vida jjajajajja
/*ll num(ll a, ll b, ll n) {
  if (n == 0) return a;

  REP (i, 0, 10) {
    ll newA = a * 10 + i;
    if (newA % b == 0) {
      ll t = num(newA, b, n - 1);
      if (t != -1) return t; 
    }
  }
  
  return -1;
}*/

string num(ll a, ll b, ll n) {
  REP (i, 0, 10) {
    ll newA = a * 10 + i;
    if (newA % b == 0) {
      string s = to_string(newA);
      REP (j, 0, n - 1) s += '0';
      return s;
    }
  }
  return "-1";
}

int main() {
  ll a, b, n;
  cin >> a >> b >> n;

  cout << num(a, b, n) << endl;
}
