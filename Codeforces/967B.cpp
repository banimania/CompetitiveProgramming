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

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  vll hs(n);
  SCAN(hs, n);

  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }

  ll firstHole = hs[0];

  hs.erase(hs.begin());

  SORTDESC(hs);

  vll suma(hs.size());
  REP (i, 0, hs.size()) {
    suma[i] = hs[i] + (i == 0 ? 0 : suma[i - 1]);
  }

  REP (i, 0, hs.size() + 1) {
    int s = firstHole + suma[hs.size() - 1] - (i == 0 ? 0 : suma[i - 1]);
    double v = (firstHole * a) / (double) s;
    if (v >= b) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;

}
