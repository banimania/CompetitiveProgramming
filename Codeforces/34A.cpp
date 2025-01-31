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
  ll n;
  cin >> n;
  vll a(n);
  SCAN(a);

  pair<int, int> reco;
  ll min = 1001;
  REP (i, 0, n) {
    ll neighbour = !i ? n - 1 : i - 1;
    ll heightDif = abs(a[i] - a[neighbour]);
    if (heightDif < min) {
      min = heightDif;
      reco.first = i + 1;
      reco.second = neighbour + 1;
    }
  }

  cout << reco.first << " " << reco.second << endl;
}
