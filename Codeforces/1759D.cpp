#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void factorize(int n, map<int, int> &factors) {
  for (int d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      factors[d]++;
      n /= d;
    }
  }
  if (n > 1) factors[n]++;
}

void solve() {
  ll n, m;
  cin >> n >> m;

  map<int, int> factors;
  factorize(n, factors);

  ll k = 1;

  while (k <= m) {
    if (factors[2] > factors[5]) {
      if (k * 5 > m) break;
      k *= 5;
      factors[5]++;
    } else if (factors[5] > factors[2]) {
      if (k * 2 > m) break;
      k *= 2;
      factors[2]++;
    } else {
      if (k * 10 > m) break;
      k *= 10;
      factors[5]++;
      factors[2]++;
    }
  }

  ll rest = (n * m) / (n * k);
  k *= rest;

  cout << n * k << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
