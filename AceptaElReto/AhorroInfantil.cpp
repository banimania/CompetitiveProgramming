#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    int suma = 0, maximo = 0;
    for (int i = 0, x; i < n; i++) {
      cin >> x;

      suma += x;

      if (maximo < suma) {
        maximo = suma;
      }
    }

    cout << suma << " " << maximo << "\n";
  }
  return 0;
}
