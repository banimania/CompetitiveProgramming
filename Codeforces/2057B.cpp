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

#define TESTCASES true 

void solve() {
  ll n, k;
  cin >> n >> k;
  vll a(n);
  SCAN(a);

  map<ll, ll> freq;
  REP (i, 0, n) {
    freq[a[i]]++;
  }

  vector<pair<ll, ll>> freqV;
  for (pair<ll, ll> par : freq) {
    freqV.push_back({par.first, par.second});
  }

  sort(freqV.begin(), freqV.end(), [](const pair<ll, ll>& x, const pair<ll, ll>& y) {
    return x.second < y.second;
  });

  ll removed = 0;
  for (int i = 0; i < freqV.size() && k > 0; i++) {
    if (k >= freqV[i].second) {
      removed++;
      k -= freqV[i].second;
    } else break;
  }

  cout << max((ll)1, (ll)(freqV.size() - removed)) << endl;
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
