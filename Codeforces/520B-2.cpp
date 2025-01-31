#include <cctype>
#include <iostream>
#include <math.h>
#include <queue>
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
  ll n, m;
  cin >> n >> m;

  if (n > m) {
    cout << n - m << endl;
    return 0;
  }

  queue<ll> cola;

  cola.push(n);

  vector<int> operations(20000, -1);
  operations[n] = 0;

  while (!cola.empty()) {
    ll v = cola.front();
    cola.pop();

    ll left = v - 1;
    ll right = v * 2;

    if (left > 0 && operations[left] == -1) cola.push(left), operations[left] = operations[v] + 1;
    if (right < 2 * m && operations[right] == -1) cola.push(right), operations[right] = operations[v] + 1;
  }

  cout << operations[m] << endl;

  return 0;
}
