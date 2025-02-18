#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    char barra;
    cin >> a >> barra >> b;

    cout << (a >= b ? "BIEN" : "MAL") << endl;
  }
  return 0;
}
