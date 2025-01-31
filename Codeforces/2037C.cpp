#include <bits/stdc++.h>
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

#define TESTCASES true 

bool isComposite(vll a) {
  REP (i, 0, a.size() - 1) {
    bool divisors = false;
    ll sum = a[i] + a[i + 1];
    REP (i, 2, ceil(sqrt(sum)) + 1) {
      if (sum % i == 0) {
        divisors = true;
        break;
      }
    }
    if (!divisors) {
      cout << sum << " no es compuesto" << endl;
      return false;
    }
  }
  return true;
}

bool isCompositeN(ll n) {
  bool divisors = false;
  REP (i, 2, ceil(sqrt(n)) + 1) {
    if (n % i == 0) {
      divisors = true;
      break;
    }
  }
  return divisors;
}

void solve() {
  ll n;
  cin >> n;

  vll a;

  int pares = n / 2;
  int impares = n / 2 + 1;

  if (n % 2 == 0) impares--;

  for (int i = pares; i > 0; i--) {
    a.push_back(2 * i);
  }

  for (int i = impares; i > 0; i--) {
    a.push_back(2 * i - 1);
  }

  for (int i = 0; i < pares; i++) {
    ll par = a[i];
    for (int j = pares; j < a.size(); j++) {
      ll impar = a[j];
      if (isCompositeN(par + impar)) {
        swap(a[pares - 1], a[i]);
        swap(a[pares], a[j]);
        PRINTLN(a);
        return;
      }
    }
  }

  cout << -1 << endl;
  return;

  /*int i = 0;
  while (!isCompositeN(a[pares] + a[pares - 1]) && i != pares - 1) {
    swap(a[i], a[pares]);
    i++;
  }*/

  /*PRINTLN(a);
  REP (i, 0, n - 1) {
    cout << a[i] + a[i + 1] << " ";
  }
  cout << endl;*/
  /*if (isCompositeN(a[pares] + a[pares - 1])) {
    PRINTLN(a);
    return;
  }*/

  //cout << -1 << endl;
  /*REP (i, 0, n - 1) {
    cout << a[i] + a[i + 1] << " ";
  }
  cout << endl;*/

  //cout << isComposite(a) << endl;

}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
