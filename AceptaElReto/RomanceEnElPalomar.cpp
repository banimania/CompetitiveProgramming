#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    cout << (n <= m ? "ROMANCE" : "PRINCIPIO") << "\n";
  }

  return 0;
}
