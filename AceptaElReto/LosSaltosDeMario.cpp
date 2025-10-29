#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;

  int arriba, abajo, last, curr, n;
  while (t--) {
    cin >> n;

    arriba = 0, abajo = 0;
    cin >> last;
    for (int i = 1; i < n; i++) {
      cin >> curr;

      if (curr > last) {
        arriba++;
      } else if (curr < last) {
        abajo++;
      }

      last = curr;
    }

    cout << arriba << " " << abajo << "\n";
  }
  return 0;
}
