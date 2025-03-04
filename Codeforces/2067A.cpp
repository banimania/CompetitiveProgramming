#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    ll a, b;
    cin >> a >> b;
    cout << (((a + 1 == b) || (((a + 1 - b) % 9 == 0) && (a + 1 - b) / 9 > 0)) ? "Yes" : "No") << endl;
  }
  return 0;
}
