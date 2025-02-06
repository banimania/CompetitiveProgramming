#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;
 
#define REP(i, a, b) for (int i = a; i < b; ++i)
#define REPV(i, a, b) for (int i = a; i >= b; --i)
#define SCAN(a) for (int i = 0; i < a.size(); ++i) cin >> a[i]
#define PRINT(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; }
#define PRINTLN(a) for (int i = 0; i < a.size(); ++i) { cout << a[i] << " "; } cout << endl
#define SORTASC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x < y; })
#define SORTDESC(a) sort(a.begin(), a.end(), [](auto x, auto y) { return x > y; })
#define FIND(a, target) find(a.begin(), a.end(), target) - a.begin()
#define UPPER(a, target) upper_bound(a.begin(), a.end(), target) - a.begin()
#define LOWER(a, target) lower_bound(a.begin(), a.end(), target) - a.begin()
#define MAX(a) distance(a.begin(), max_element(a.begin(), a.end()))
#define MIN(a) distance(a.begin(), min_element(a.begin(), a.end()))

const ll MOD = 1e9 + 7;

#define TESTCASES false

void solve() {
  string numLine;
  getline(cin, numLine);

  int n = stoi(numLine);
  while (n--) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    string fixed = "";
    REP (i, 0, s1.length()) if (s1[i] != ' ' && s1[i] != ',' && s1[i] != '.' && s1[i] != ';' && s1[i] != ':') fixed += tolower(s1[i]);
    
    string fixed2 = "";
    REP (i, 0, s2.length()) if (s2[i] != ' ' && s2[i] != ',' && s2[i] != '.' && s2[i] != ';' && s2[i] != ':') fixed2 += tolower(s2[i]);

    cout << (fixed == fixed2 ? "SI" : "NO") << endl;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;

  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
