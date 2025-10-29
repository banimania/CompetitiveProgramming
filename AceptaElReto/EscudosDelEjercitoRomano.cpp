#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    int escudos = 0;
    while (n > 0) {
      int lado = (int) sqrt(n);
      n -= lado * lado;

      escudos += (lado * lado) + 4 * lado;
    }

    cout << escudos << endl;
  }

  return 0;
}
