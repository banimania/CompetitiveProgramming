#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

void solve() {
  ll n;
  cin >> n;

  vector<vector<ll>> a(n, vector<ll>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  if (n == 1) {
    cout << "YES" << endl;
    cout << 7 << endl;
    return;
  }

  vector<ll> sol(n, -1);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      sol[i] &= a[i][j];
    }
    if (sol[i] == -1) sol[i] = 0;
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;

      if ((sol[i] | sol[j]) != a[i][j]) {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; i++) {
    cout << sol[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
