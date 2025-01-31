#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

int main() {
  ll t; cin >> t;
  while (t--) {
    ll n, m; cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }

    if (n * m == 1) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << a[(i + 1) % n][(j + 1) % m] << " ";
      }
      cout << endl;
    }
  }
  

}
