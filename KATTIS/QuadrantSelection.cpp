#include <bits/stdc++.h>
using namespace std;

int main() {
  int x, y;
  cin >> x >> y;

  int q = 1;
  if (x > 0 && y < 0) q = 4;
  else if (x < 0 && y > 0) q = 2;
  else if (x < 0 && y < 0) q = 3;

  cout << q << endl;
  return 0;
}
