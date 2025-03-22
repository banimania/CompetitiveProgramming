#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  if (a < min(b, c)) {
    cout << "Monnei" << endl;
  } else if (b < min(a, c)) {
    cout << "Fjee" << endl;
  } else {
    cout << "Dolladollabilljoll" << endl;
  }
  return 0;
}
