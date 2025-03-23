#include <bits/stdc++.h>
using namespace std;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int ans = 2;
  if (x1 == x2 || y1 == y2) ans = 1;
  cout << ans << endl;
  return 0;
}
