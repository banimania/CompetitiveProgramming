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

int main() {
  string a;
  cin >> a;
  string b;
  cin >> b;

  if (a.length() != b.length()) {
    cout << "NO" << endl;
    return 0;
  }
  
  /*REP (i, 0, a.length()) {
    if (a[i] == b[i]) continue;
    bool possible = false;
    if (b[i] == '1') {
      if (i > 0 && ((a[i] == '1' && a[i - 1] == '0') || (a[i] == '0' && a[i - 1] == '1') || (a[i] == '1' && a[i - 1] == '1'))) possible = true;
      if (i < a.length() - 1 && ((a[i] == '1' && a[i + 1] == '0') || (a[i] == '0' && a[i + 1] == '1') || (a[i] == '1' && a[i + 1] == '1'))) possible = true;
    } else {
      if (i > 0 && ((a[i] == '0' && a[i - 1] == '0') || (a[i] == '1' && a[i - 1] == '1'))) possible = true;
      if (i < a.length() - 1 && ((a[i] == '0' && a[i + 1] == '0') || (a[i] == '1' && a[i + 1] == '1'))) possible = true;
    }

    if (!possible) {
      cout << "NO" << endl;
      return 0;
    }
  }*/

  int cerosA = 0;
  int cerosB = 0;
  REP (i, 0, a.length()) {
    if (a[i] == '0') cerosA++;
    if (b[i] == '0') cerosB++;
  }
  int unosA = a.length() - cerosA;
  int unosB = a.length() - cerosB;

  if ((unosA == 0 && unosB != 0)
      || (unosA > 0 && unosB == 0)) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  return 0;
}
