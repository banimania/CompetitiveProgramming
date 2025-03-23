#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  double discr = b * b - 4 * a * c;
  if (discr < 0) {
    cout << 0 << endl;
    return 0;
  }

  double root = sqrt(discr);
  double r1 = (-b + root) / (2 * a);
  double r2 = (-b - root) / (2 * a);

  if (r1 == r2) {
    cout << 1 << endl;
    return 0;
  }
  cout << 2 << endl;
  return 0;
}
