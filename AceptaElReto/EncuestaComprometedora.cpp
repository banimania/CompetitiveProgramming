#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    cout << ((a - b) * 100) / (a + b) << "\n";
  }

  return 0;
}
