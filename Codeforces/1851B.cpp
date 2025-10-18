#include <iostream>
#include <numeric>
#include <algorithm>

#define ll long long

using namespace std;

void solve() {
  ll n;
  cin >> n;

  ll a[n];
  bool rb[n];
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 0) {
      rb[i] = true;
    } else {
      rb[i] = false;
    }
  }

  ll indexes[n];
  iota(indexes, indexes + n, 0);
  stable_sort(indexes, indexes + n, [&](ll i, ll j) {
    return a[i] < a[j];
  });

  for (ll i = 0; i < n; i++) {
    if (rb[i] ^ rb[indexes[i]]) {
      cout << "NO\n";
      return;
    }
  }

  cout << "YES\n";
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
