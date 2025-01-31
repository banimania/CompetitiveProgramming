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

/*int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  SCAN(a);

  int m;
  cin >> m;
  vector<int> b(m);
  SCAN(b);

  int vasya = 0;
  int petya = 0;

  REP (i, 0, m) {
    int target = b[i];

    int index = FIND(a, target);

    vasya += index + 1;
    petya += n - index;
  }

  cout << vasya << " " << petya << endl;
  return 0;
}*/

int main() {
  int n;
  cin >> n;
  int total = 0;
  REP (i, 0, n) {
    int a;
    cin >> a;
    total += a;
  }

  int ans = 0;
  REP (i, 1, 6) {
    if ((total + i) % (n + 1) != 1) {
      ans++;
    }
  }
  cout << ans << endl;
}
