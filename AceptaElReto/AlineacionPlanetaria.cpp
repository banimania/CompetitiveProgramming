#include <bits/stdc++.h>
using namespace std;

int __lcm(int a, int b) {
  return (a * b) / __gcd(a, b);
}

int main() {
  int n;
  while (cin >> n && n) {
    int lcm = 1;

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;

      lcm = __lcm(lcm, x);
    }

    cout << lcm << endl;
  }
  return 0;
}
