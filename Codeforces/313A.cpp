#include <cctype>
#include <cmath>
#include <iostream>
#include <algorithm>
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
  int n;
  cin >> n;

  if (n >= 0) {
    cout << n << endl;
    return 0;
  }

  string s = to_string(n);
  if (s.length() == 2) {
    cout << n << endl;
    return 0;
  }

  if (s.length() >= 3) {
    string s1 = "";
    string s2 = "";
    REP (i, 0, s.length()) {
      if (i == s.length() - 1) s1 += s[i];
      else if (i == s.length() - 2) s2 += s[i];
      else s1 += s[i], s2 += s[i];
    }
    cout << max(stoi(s1), stoi(s2)) << endl;
  }

  return 0;
}
