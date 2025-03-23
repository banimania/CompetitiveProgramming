#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    if (i & 1) {
      cout << s << endl;
    }
  }

  return 0;
}
