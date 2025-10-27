#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  while (cin >> a >> b) {
    if (!a && !b) break;

    float x = (a * b) / 2.0f;

    cout << fixed << setprecision(1) << x << "\n";
  }
  return 0;
}
