#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int i, j;
  while (cin >> i >> j) {
    if (!i && !j) break;

    if (i == 1) cout << 'h';
    else if (i == 2) cout << 'g';
    else if (i == 3) cout << 'f';
    else if (i == 4) cout << 'e';
    else if (i == 5) cout << 'd';
    else if (i == 6) cout << 'c';
    else if (i == 7) cout << 'b';
    else if (i == 8) cout << 'a';

    cout << j << '\n';
  }
  return 0;
}
