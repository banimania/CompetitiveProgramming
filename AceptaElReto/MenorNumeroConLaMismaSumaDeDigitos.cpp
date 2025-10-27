#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int n;
  while (cin >> n && n) {
    int minDig = (n / 9) + (n % 9 != 0);

    string num = string(minDig, ' ');

    int curr = n;
    for (int i = 0; i < minDig; i++) {
      int actual = min(9, curr);

      num[minDig - i - 1] = (char) (actual + '0');
      curr -= actual;
    }

    cout << num << "\n";
  }
  return 0;
}
