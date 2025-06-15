#include <bits/stdc++.h>
using namespace std;

#define TESTCASES 0

typedef long long ll;

void solve() {
  ll n;
  while (cin >> n) {
    ll sqrtN = sqrt(n);

    cout << (n == sqrtN * sqrtN ? "ENCENDIDA" : "APAGADA") << endl;
  }
}

int main() {
  int t = 1;
  if (TESTCASES) cin >> t;
  for (int i = 0; i < t; i++) solve();
  return 0;
}
