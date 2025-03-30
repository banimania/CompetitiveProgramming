#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  double o1 = 100 * (1.0 / n);
  double o2 = 100 * (1.0 / (100 - n));

  cout << fixed << setprecision(3) << o1 << endl << o2 << endl;

  return 0;
}
