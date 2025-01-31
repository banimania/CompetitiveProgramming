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

#define TESTCASES false

void bfs(ll start, unordered_set<ll> aSet, vll &sortedArray, ll maxValue) {
  queue<ll> cola;
  unordered_set<ll> visitado;

  cola.push(start);
  while (!cola.empty()) {
    ll actual = cola.front();
    cola.pop();
    if (aSet.count(actual)) sortedArray.push_back(actual);
    visitado.insert(actual);

    if (actual % 3 == 0 && !visitado.count(actual / 3)) cola.push(actual / 3), visitado.insert(actual / 3);
    if (actual * 2 <= maxValue && !visitado.count(actual * 2)) cola.push(actual * 2), visitado.insert(actual * 2);
  }
}

void solve() {
  ll n;
  cin >> n;
  vll a(n);
  SCAN(a, n);

  SORTDESC(a);

  unordered_set<ll> aSet(a.begin(), a.end());

  vll sortedArray;
  ll maxValue = a[MAX(a)];
  REP (i, 0, n) {
    bfs(a[i], aSet, sortedArray, maxValue);

    if (sortedArray.size() == n) break;
    else sortedArray.clear();
  }

  PRINTLN(sortedArray);
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
