#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAXN = 5;
vector<ll> fac(MAXN + 1);

void factorial() {
  fac[0] = 1;
  for (int i = 1; i <= MAXN; i++) fac[i] = fac[i - 1] * i;
}

int main() {
  factorial();

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    if (n >= 5) {
      cout << 0 << endl;
    } else {
      cout << fac[n] % 10 << endl;
    }
  }
  return 0;
}
