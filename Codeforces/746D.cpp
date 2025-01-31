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
  ll n, k, a, b;
  cin >> n >> k >> a >> b;

  string s;

  char currChar = (a > b ? 'G' : 'B');
  int currCount = 0;
  int aCount = 0, bCount = 0;
  REP (i, 0, n) {

    if (a - aCount > b - bCount) currChar = 'G';
    else currChar = 'B';

    if (currCount == k) {
      if (s[i - 1] == 'B') currChar = 'G';
      else currChar = 'B';
    }

    s += currChar;

    if (s[i] == 'G') aCount++;
    else bCount++;
    
    if (i == 0) currCount = 1;
    else {
      if (s[i] == s[i - 1]) currCount++;
      else currCount = 1;
    }
  }

  int aCountFinal = 0, bCountFinal = 0;
  int maxStraight = 0;
  int straight = 0;
  REP (i, 0, s.length()) {
    if (i == 0) {
      straight++;
    } else {
      if (s[i] == s[i - 1]) straight++;
      else straight = 1;
    }
    maxStraight = fmax(straight, maxStraight);
    if (s[i] == 'G') aCountFinal++;
    else bCountFinal++;
  }

  if (maxStraight > k || aCountFinal != a || bCountFinal != b) {
    cout << "NO" << endl;
    return;
  }

  cout << s << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
