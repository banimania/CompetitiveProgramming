#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h, c;
  while (cin >> h >> c) {
    if (!h && !c) break;

    cout << ((h / c) - (h % c == 0) + 1) * 10 << "\n";
  }
  return 0;
}
