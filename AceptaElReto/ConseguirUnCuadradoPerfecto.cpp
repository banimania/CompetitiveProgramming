#include <bits/stdc++.h>
using namespace std;

void factoresPrimos(int n, unordered_map<int, int> &fact, const vector<int> &primos) {
  for (int p : primos) {
    if (p == 1) break;
    while (n % p == 0) {
      fact[p]++;
      n /= p;
    }
  }

  if (n > 1) fact[n]++;
}

void calcPrimos(vector<int> &primos) {
  vector<bool> esPrimo(46342, true);
  esPrimo[0] = false;
  esPrimo[1] = false;
  for (int i = 2; i < esPrimo.size(); i++) {
    if (esPrimo[i]) {
      primos.push_back(i);
      for (int j = 2 * i; j < esPrimo.size(); j += i) {
        esPrimo[j] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<int> primos;
  calcPrimos(primos);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    unordered_map<int, int> fact;
    factoresPrimos(n, fact, primos);

    int ans = 1;
    for (const pair<int, int> &p : fact) {
      if (p.second % 2) ans *= p.first;
    }
    cout << ans << "\n";
  }
  return 0;
}
