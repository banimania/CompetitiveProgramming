#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll n, h;
    cin >> n >> h;

    cout << (h / n) + (h % n) << "\n";
  }

  return 0;
}
