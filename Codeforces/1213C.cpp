#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, m;
  cin >> n >> m;

  set<ll> seen;
  ll i = m;
  ll ciclo = 0;
  ll end;
  while (true) {
    ll imod = i % 10;
    if (seen.count(imod)) break;

    seen.insert(imod);
    ciclo += imod;
    end = i;

    i += m;
  }
  ll ciclosEnteros = n / end;
  ll ans = ciclosEnteros * ciclo;

  i = ciclosEnteros * end + m;
  while (i <= n) {
    ans += (i % 10);

    i += m;
  }

  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
  return 0;
}
