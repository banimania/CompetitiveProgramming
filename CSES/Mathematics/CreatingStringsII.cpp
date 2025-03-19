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
const ll MAXN = 1e6 + 5;
vector<ll> fac(MAXN + 1);
vector<ll> inv(MAXN + 1);

void factorial() {
  fac[0] = 1;
  for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i % MOD;
}

void inverses() {
  inv[MAXN] = modExp(fac[MAXN], MOD - 2, MOD);
  for (int i = MAXN; i >= 1; i--) inv[i - 1] = inv[i] * i % MOD;
}

int main() {
  factorial();
  inverses();

  string s;
  cin >> s;

  map<char, ll> freq;
  for (int i = 0; i < s.length(); i++) {
    freq[s[i]]++;
  }

  ll ans = fac[s.length()];

  for (auto [c, t] : freq) {
    ans = (ans * inv[t]) % MOD;
  }

  cout << ans << endl;

  return 0;
}
