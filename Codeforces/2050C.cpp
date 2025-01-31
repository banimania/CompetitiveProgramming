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

#define TESTCASES true

ll sumDigitsString(string num) {
  ll sum = 0;
 
  REP (i, 0, num.length()) {
    sum += num[i] - '0';
  }
 
  return sum;
}
 
void solve() {
  string num;
  cin >> num;

  ll sum = sumDigitsString(num);
  if (sum % 9 == 0) {
    cout << "YES" << endl;
    return;
  }

  ll doses = 0;
  ll treses = 0;

  REP (i, 0, num.length()) {
    if (num[i] == '2') doses++;
    if (num[i] == '3') treses++;
  }

  REP (i, 0, doses + 1) {
    REP (j, 0, treses + 1) {
      if ((sum + i * 2 + j * 6) % 9 == 0) {
        cout << "YES" << endl;
        return;
      }
    } 
  }


  cout << "NO" << endl;
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
