#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, g, b;
  cin >> n >> g >> b;

  ll ans = 0;

  ll minGood = ceil(n / 2.0);
  ll maxBad = n - minGood;

  ll neededCyclesGood = minGood / g;
  if (neededCyclesGood > 0 && minGood % g == 0) neededCyclesGood--;

  ll takenFullGood = neededCyclesGood * (g + b);
  ans += takenFullGood + (minGood - takenFullGood) + neededCyclesGood * b;

  cout << max(ans, n) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
