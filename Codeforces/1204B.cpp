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
  ll n, l, r;
  cin >> n >> l >> r;

  int cnt = 1;
  int min = n;
  int aux = n;
  int lastPow = pow(2, 0);
  while (cnt <= l) {
    min += pow(2, cnt - 1) - 1;
    lastPow = pow(2, cnt);
    cnt++;
    aux--;
  }

  cnt = 1;
  int max = n;
  aux = n;
  lastPow = pow(2, 0);
  while (cnt != r) {
    max += (aux - 1) * pow(2, cnt) - lastPow * (aux - 1);
    lastPow = pow(2, cnt);
    cnt++;
    aux--;
  }

  cout << min << " " << max << endl;

}
