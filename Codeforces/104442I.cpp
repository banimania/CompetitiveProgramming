#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll MAXN = 531500;

map<string, string> memo;

vector<ll> fact(MAXN, -1);

ll factorial(ll n) {
  if (fact[n] != -1) return fact[n];

  return fact[n] = (n * factorial(n - 1)) % MOD;
}

string calcNum(ll x, ll y) {
  ll powX = x * x * x * x * x * x;
  ll powY = y * y * y * y * y * y;

  ll r1 = (x == 1 ? powY : factorial(powY));
  ll r2 = (y == 1 ? powX : factorial(powX));

  ll num = ((47 * r1 + r2) % 9999) + 1;

  return to_string(num);
}

void precalc() {
  for (int i = 11; i <= 99; i++) {
    int x = i / 10, y = i % 10;
    if (y) {
      string curr;
      curr += (x + '0');
      curr += (y + '0');

      memo[curr] = calcNum(x, y);
    }
  }
}

int main() {
  fact[0] = 1;

  for (int i = 1; i < MAXN; i++) {
    factorial(i);
  }
  precalc();

  string a;
  while (cin >> a) {
    if (a == "0") break;

    for (int i = 0; i < a.size(); i += 2) {
      string sub = a.substr(i, 2);
      cout << memo[sub];
    }
    cout << endl;
  }
  return 0;
}
