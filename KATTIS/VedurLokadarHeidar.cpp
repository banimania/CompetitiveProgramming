#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, v;
  cin >> v >> n;
  for (int i = 0; i < n; i++) {
    int k;
    string s;
    cin >> s >> k;

    cout << s << " ";
    if (v <= k) {
      cout << "opin";
    } else {
      cout << "lokud";
    }
    cout << "\n";
  }

  return 0;
}
