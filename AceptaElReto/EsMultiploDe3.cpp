#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    long long suma = ((n % 3 * (n + 1) % 3) / 2) % 3;
    cout << (suma == 0 ? "SI" : "NO") << endl;
  }
  return 0;
}
