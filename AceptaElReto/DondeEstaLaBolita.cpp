#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, i;
  while (cin >> n >> i) {
    if (!n && !i) break;

    i--;

    int a, b;
    while (cin >> a >> b) {
      if (!a && !b) break;

      a--, b--;

      if (i == a) i = b;
      else if (i == b) i = a;
    }

    cout << i + 1 << endl;
  }
  return 0;
}
