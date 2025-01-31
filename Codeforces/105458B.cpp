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

  vector<string> matriculas(n);

  REP (i, 0, n) {
    cin >> matriculas[i];
  }

  sort(matriculas.begin(), matriculas.end(), [](string a, string b) {
    int numA = stoi(a.substr(0, 4));
    int numB = stoi(b.substr(0, 4));
    REP (i, 4, 7) {
      if (a[i] == b[i]) continue;
      else if (a[i] > b[i]) return true;
      else if (b[i] > a[i]) return false;
    }

    if (numA > numB) return true;
    else if (numB > numA) return false;
    else return true;
  });

  cout << matriculas[n - 1] << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
