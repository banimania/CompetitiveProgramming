#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    char c; int n, m;
    cin >> c >> n >> m;

    if (c == 'k') cout << (m * n) / 2 << endl;
    else if (c == 'Q') cout << min(m, n) << endl;
    else if (c == 'K') cout << ceil(m / 2.0f) * ceil(n / 2.0f) << endl;
    else cout << min(m, n) << endl;
  }
  return 0;
}
