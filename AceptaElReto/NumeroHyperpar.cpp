#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string n;
  while (cin >> n && n[0] != '-') {
    bool ans = true;
    for (int i = 0; i < n.size(); i++) {
      if (n[i] % 2) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "SI\n" : "NO\n");
  }

  return 0;
}
