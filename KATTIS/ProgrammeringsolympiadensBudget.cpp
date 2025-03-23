#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int t = 0;
  for (int i = 0; i < n; i++) {
    string s;
    int k;
    cin >> s >> k;
    t += k;
  }

  if (!t) {
    cout << "Lagom" << endl;
  } else if (t > 0) {
    cout << "Usch, vinst" << endl;
  } else if (t < 0) {
    cout << "Nekad" << endl;
  }

  return 0;
}
