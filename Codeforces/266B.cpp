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

int main() {
  int n, t;
  cin >> n >> t;
  string s;
  cin >> s;

  REP (i, 0, t) {
    string s2 = s;
    for (int j = 1; j < n; j++) {
      if (s[j] == 'G' && s[j - 1] == 'B') swap(s2[j], s2[j - 1]);
    }
    s = s2;
  }

  cout << s << endl;

  return 0;
}
