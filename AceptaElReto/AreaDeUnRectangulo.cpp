#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll x1, y1, x2, y2;
  while (cin >> x1 >> y1 >> x2 >> y2) {
    if (x2 < x1 || y2 < y1) return 0;
    cout << abs(x1 - x2) * abs(y1 - y2) << endl;
  }
  return 0;
}
