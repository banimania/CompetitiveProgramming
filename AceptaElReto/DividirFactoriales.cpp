#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll num, den;
  while (cin >> num >> den) {
    if (num < den) break;

    ll ans = 1;

    for (int i = den + 1; i <= num; i++) {
      ans *= i;
    }

    cout << ans << endl;
  }
  
  return 0;
}
