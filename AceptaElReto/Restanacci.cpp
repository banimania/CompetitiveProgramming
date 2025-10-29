#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, n;
  while (cin >> a >> b >> n) {
    if (!a && !b && !n) break;

    int c = b - a;

    vector<int> res = {a, b, c, -a, -b, -c};

    cout << res[n % 6] << "\n";
  }
  return 0;
}

