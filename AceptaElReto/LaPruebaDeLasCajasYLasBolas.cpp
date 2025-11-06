#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n) {
    cout << ceil(log2(n + 1)) << "\n";
  }
  return 0;
}
