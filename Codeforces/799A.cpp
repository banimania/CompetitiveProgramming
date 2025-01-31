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

int main() {
  int n, t, k, d;
  cin >> n >> t >> k >> d;

  int t1 = ceil((double)n / k) * t;

  int cakes = 0;
  int time = 0;
  int horno1 = 0;
  int horno2 = 0;
  int buildT = 0;

  while (n > cakes) {
    time++;
    horno1++;
    buildT++;

    if (horno1 == t) {
      cakes += k;
      horno1 = 0;
    }

    if (buildT >= d) {
      if (buildT > d) horno2++;
      if (horno2 == t) {
        cakes += k;
        horno2 = 0;
      }
    }
  }

  cout << (time < t1 ? "YES" : "NO") << endl;
}
