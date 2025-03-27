#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;

  if (n <= 0) {
    n = -n;
    ll sum = -(n * (n + 1) / 2) + 1;
    cout << sum << endl;
  } else {
    ll sum = n * (n + 1) / 2;
    cout << sum  << endl;
  }
  return 0;
}
