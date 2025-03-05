#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll a, b;
  while (cin >> a >> b) {
    if (a < 0 || b < 0) return 0;
    cout << 2 * abs(a) + 2 * abs(b) << endl;
  }
  return 0;
}
