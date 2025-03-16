#include <bits/stdc++.h>
using namespace std;

int main() {
  int c;
  while (cin >> c && c) {
    if (c == 1) cout << 1 << endl;
    else cout << (c % 2 ? c - 1 : c) << endl;
  }
  return 0;
}
