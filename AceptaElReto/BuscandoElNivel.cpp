#include <iostream>

#define ll long long

using namespace std;

void solve(ll n) {
  ll a[n];
  for (ll i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll ps[n + 1];
  ps[0] = 0;
  for (ll i = 1; i <= n; ++i) {
    ps[i] = ps[i - 1] + a[i - 1];
  }

  ll q;
  cin >> q;

  while (q--) {
    ll a, b;
    cin >> a >> b;
    cout << ps[b - 1] - ps[a] << "\n";
  }

  cout << "---\n";
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll n;
  while (cin >> n && n != 0) {
    solve(n);
  }


  return 0;
}
