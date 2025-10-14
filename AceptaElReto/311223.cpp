#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    vector<string> v(3);
    for (int i = 0; i < 3; i++) cin >> v[i];

    sort(v.begin(), v.end());
    bool divertido = false;
    do {
      if (v[0][0] == v[1][1] && v[0][1] == v[2][0] && v[1][0] == v[2][1]) {
        divertido = true;
        break;
      }
    } while (next_permutation(v.begin(), v.end()));

    cout << (divertido ? "DIVERTIDOS" : "INSULSOS") << '\n';
  }
  return 0;
}
