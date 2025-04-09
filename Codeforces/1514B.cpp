#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

template<typename T>
T modExp(T base, T exp, T mod) {
  T result = 1;
  base %= mod;

  while (exp > 0) {
    if (exp % 2 == 1) result = (result * base) % mod;

    base = (base * base) % mod;
    exp /= 2;
  }

  return result;
}

const ll MOD = 1e9 + 7;

void solve() {
  ll n, k;
  cin >> n >> k;

  cout << modExp(n, k, MOD) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
