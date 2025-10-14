#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  int ridesFull = (n / m) + 1 - (n % m == 0);
  int ridesFullNS = (n / m);

  int opc1 = ridesFull * b;
  int opc2 = ridesFullNS * b + (n - (ridesFullNS * m)) * a;
  int opc3 = n * a;
  cout << min({opc1, opc2, opc3}) << endl;

  return 0;
}
