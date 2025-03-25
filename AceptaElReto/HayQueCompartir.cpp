#include <bits/stdc++.h>
using namespace std;

int __lcm(int a, int b) {
  return a / __gcd(a, b) * b;
}

int main() {
  int n;
  int a, b;
  while (cin >> n && n) {
    int lcm = 1;
    int total = 0;

    vector<int> numerador(n), denominador(n);
    for (int i = 0; i < n; i++) {
      cin >> a;
      cin.ignore();
      cin >> b;
      numerador[i] = a;
      denominador[i] = b;
      lcm = __lcm(lcm, b);
    }

    for (int i = 0; i < n; i++) {
      total += (lcm / denominador[i]) * numerador[i];
    }

    cout << lcm - total << endl;
  }
  return 0;
}
