#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  while (cin >> n && n) {
    int suma = 0;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      suma += x;
    }

    cout << suma << endl;
  }
  return 0;
}
