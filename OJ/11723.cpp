#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, r;
  int cnt = 1;
  while (cin >> n >> r) {
    if (!n && !r) return 0;
    cout << "Case " << cnt << ": ";
    int amount = n / r;

    if (amount > 26) {
      cout << "impossible";
    } else {
      if (n % r == 0) {
        amount--;
      }
      cout << amount;
    }

    cout << endl;
    cnt++;
  }
  return 0;
}
