#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int e;
  while (cin >> e && e) {
    int n;
    cin >> n;

    int x, suma = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      suma += x;
    }

    cout << (suma / e + 1) - (suma % e == 0) << "\n";
  }
  return 0;
}
