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

void solve() {
  ll n;
  cin >> n;
  vll a(n);
  vector<ll> veces(1e6 + 10, 0);
  map<ll, ll> firstIndex, lastIndex;
  ll maxCount = -1;
  ll maxIndex = -1;
  REP (i, 0, n) {
    cin >> a[i];
    a[i]--;
    if (!veces[a[i]]) firstIndex[a[i]] = i;
    lastIndex[a[i]] = i;
    veces[a[i]]++;
    if (veces[a[i]] > maxCount) {
      maxCount = veces[a[i]];
      maxIndex = i;
    }
  }
  
  vector<ll> maxIndexes;
  ll smallest = LLONG_MAX;
  REP (i, 0, n) {
    if (veces[a[i]] >= maxCount) {
      ll dif = lastIndex[a[i]] - firstIndex[a[i]];
      if (dif < smallest) {
        smallest = dif;
        maxIndex = i;
      }
    }
  }


  ll l = firstIndex[a[maxIndex]] + 1, r = lastIndex[a[maxIndex]] + 1;
  
  cout << l << " " << r << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
