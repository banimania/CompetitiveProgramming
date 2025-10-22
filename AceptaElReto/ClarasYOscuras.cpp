#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;

    int x = a * b;

    int h = x / 2;
    if (x % 2 == 0) {
      cout << h << " " << h << "\n";
    } else {
      cout << h + 1 << " " << h << "\n";
    }
  }
  return 0;
}
