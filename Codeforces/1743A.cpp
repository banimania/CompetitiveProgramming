#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const ll MAXN = 10;
vector<ll> fac(MAXN + 1);
vector<ll> inv(MAXN + 1);

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

void factorial() {
  fac[0] = 1;
  for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}

void inverses() {
  inv[MAXN] = modExp(fac[MAXN], MOD - 2, MOD);
  for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

ll choose(int n, int r) {
  return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
  factorial();
  inverses();
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
    }

    cout << 6 * choose(10 - n, 2) << endl;
  }
  return 0;
}
