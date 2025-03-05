#include <bits/stdc++.h>
using namespace std;

vector<bool> primos(100005, true);

int main() {
  primos[0] = false, primos[1] = false;
  for (int i = 2; i < primos.size(); i++) {
    if (primos[i]) {
      for (int j = 2 * i; j < primos.size(); j += i) {
        primos[j] = false;
      }
    }
  }

  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;

    double maxError = pow(10, -m);

    double nPrimos = 0;
    for (int i = 2; i <= n; i++) {
      if (primos[i]) nPrimos++;
    }

    double error = abs((nPrimos / n) - (1 / log(n)));

    if (error == maxError) {
      cout << "Igual" << endl;
    } else if (error > maxError) {
      cout << "Mayor" << endl;
    } else {
      cout << "Menor" << endl;
    }

  }
  return 0;
}
