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
 
int main() {
  ll n, t;
  cin >> n >> t;
  vll a(n - 1);
  SCAN(a, n - 1);

  vector<bool> visitado(n, false);

  visitado[n - 1] = true;
  int x = 1;
  
  while (x != t) {
    if (visitado[x - 1]) {
      cout << "NO" << endl;
      return 0;
    }

    visitado[x - 1] = true;

    x += a[x - 1];
  }
  cout << "YES" << endl;
}
