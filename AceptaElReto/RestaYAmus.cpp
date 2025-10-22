#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    cout << (n % 9 == 0 ? "SI" : "NO") << "\n";
  }
  return 0;
}
