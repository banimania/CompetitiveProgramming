#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int m, a, c;
    cin >> m >> a >> c;

    string s;
    cin >> s;

    bool posible = true;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'R') {
        a--, m--;
      } else if (s[i] == 'N') {
        a--, m--, c--;
      } else if (s[i] == 'V') {
        a--, c--;
      } else if (s[i] == 'L') {
        m--, c--;
      } else if (s[i] == 'A') {
        a--;
      } else if (s[i] == 'M') {
        m--;
      } else if (s[i] == 'C') {
        c--;
      }

      if (a < 0 || m < 0 || c < 0) {
        posible = false;
        break;
      }
    }

    if (!posible) {
      cout << "NO" << endl;
    } else {
      cout << "SI " << m << " " << a << " " << c << endl;
    }
  }
  return 0;
}
