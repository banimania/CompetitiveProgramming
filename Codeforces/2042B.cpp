/*
▗▄▄▄  ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖ ▗▄▖ 
▐▌  █▐▌ ▐▌▐▛▚▖▐▌  █  ▐▛▚▞▜▌▐▌ ▐▌▐▛▚▖▐▌  █  ▐▌ ▐▌
▐▌  █▐▛▀▜▌▐▌ ▝▜▌  █  ▐▌  ▐▌▐▛▀▜▌▐▌ ▝▜▌  █  ▐▛▀▜▌
▐▙▄▄▀▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌ ▐▌
*/

#include <bits/stdc++.h>
#include <queue>
#include <sstream>
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

void solve() {
  ll n;
  cin >> n;
  unordered_map<ll, ll> c;
  REP (i, 0, n) {
    ll v;
    cin >> v;
    if (c.count(v)) c[v]++;
    else c[v] = 1;
  }

  set<ll> aC;

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, function<bool(pair<ll, ll>, pair<ll, ll>)>> pq(
    [&](pair<ll, ll> a, pair<ll, ll> b) {
      if (a.second == b.second) {
        if (!aC.count(a.first)) return false;
        if (!aC.count(b.first)) return true;
      }
      return a.second > b.second;
    }
  );

  for (pair<ll, ll> par : c) {
    pq.push({par.first, par.second});
  }

  vll aliceCoins, bobCoins;
  bool aliceTurn = true;
  while (!pq.empty() && aliceCoins.size() + bobCoins.size() != n) {
    pair<ll, ll> actual = pq.top();
    pq.pop();
    if (aliceTurn) aC.insert(actual.first);
    if (aliceTurn) aliceCoins.push_back(actual.first);
    else bobCoins.push_back(actual.first);
    if (actual.second > 1) pq.push({actual.first, actual.second - 1});

    //cout << (aliceTurn ? "Alice" : "Bob") << " coge la moneda " << actual.first << " (quedan " << actual.second - 1 << ")" << endl;
    aliceTurn = !aliceTurn;
  }
  ll aliceScore = 0;
  unordered_map<ll, ll> aliceC;

  REP (i, 0, aliceCoins.size()) {
    if (aliceC.count(aliceCoins[i])) aliceC[aliceCoins[i]]++;
    else aliceC[aliceCoins[i]] = 1;
  }

  for (pair<ll, ll> par : aliceC) {
    if (par.second > 0) aliceScore++;
    if (par.second == c[par.first]) aliceScore++;
  }

  cout << aliceScore << endl;
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
