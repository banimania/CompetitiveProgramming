/*
▗▄▄▄  ▗▄▖ ▗▖  ▗▖▗▄▄▄▖▗▖  ▗▖ ▗▄▖ ▗▖  ▗▖▗▄▄▄▖ ▗▄▖ 
▐▌  █▐▌ ▐▌▐▛▚▖▐▌  █  ▐▛▚▞▜▌▐▌ ▐▌▐▛▚▖▐▌  █  ▐▌ ▐▌
▐▌  █▐▛▀▜▌▐▌ ▝▜▌  █  ▐▌  ▐▌▐▛▀▜▌▐▌ ▝▜▌  █  ▐▛▀▜▌
▐▙▄▄▀▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌  ▐▌▐▌ ▐▌▐▌  ▐▌▗▄█▄▖▐▌ ▐▌
*/

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

#define TESTCASES false

void solve() {
  ll d, sumTime;
  cin >> d >> sumTime;

  vll minTime(d), maxTime(d);
  REP (i, 0, d) cin >> minTime[i] >> maxTime[i];

  vll estudio(d);
  ll horas = 0;
  REP (i, 0, d) {
    estudio[i] = minTime[i];
    horas += minTime[i];
  }

  if (horas > sumTime) {
    cout << "NO" << endl;
    return;
  }

  REP (i, 0, d) {
    ll horasRestantes = sumTime - horas;
    if (horasRestantes <= 0) break;

    ll horasHoy = min(horasRestantes, maxTime[i] - estudio[i]);
    estudio[i] += horasHoy;
    horas += horasHoy;
  }

  if (horas != sumTime) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  PRINTLN(estudio);
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
