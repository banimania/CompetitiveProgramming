#include <iostream>

#define ll long long

using namespace std;

void solve() {
  ll n, k;
  cin >> n >> k;

  ll c[n];
  for (ll i = 0; i < n; i++) {
    cin >> c[i];
  }

  ll count = 0;
  ll index = 0;
  for (ll i = 0; i < n; i++) {
    if (c[i] == c[0]) {
      count++;
    }
    if (count == k) {
      index = i;
      break;
    }
  }

  if (count != k) {
    cout << "NO\n";
    return;
  }

  if (c[0] == c[n - 1]) {
    cout << "YES\n";
    return;
  }

  count = 0;
  for (ll i = n - 1; i >= 0; i--) {
    if (c[i] == c[n - 1]) {
      count++;
    }
    if (count == k) {
      break;
    }
    if (i <= index) {
      cout << "NO\n";
      return;
    }
  }

  if (count == k) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

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
