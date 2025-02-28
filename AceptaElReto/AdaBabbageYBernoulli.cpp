#include <bits/stdc++.h>
using namespace std;

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

int main() {
  int n, p;
  while (cin >> n >> p) {
    if (!n && !p) return 0;

    int suma = 0;

    for (int i = 1; i <= n; i++) {
      suma += modExp(i, p, 46337);
      suma %= 46337;
    }

    cout << suma << endl;
  }
  return 0;
}
