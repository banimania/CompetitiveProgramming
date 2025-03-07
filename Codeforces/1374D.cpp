#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, k;
  cin >> n >> k;

  map<ll, ll> freq;

  bool allDivisible = true;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;


    if (x % k) {
      allDivisible = false;
      freq[k - (x % k)]++;
    }
  }

  if (allDivisible) {
    cout << 0 << endl;
    return;
  }

  ll op = 0;

  for (auto [a, b] : freq) {
    op = max(op, a + (b - 1) * k + 1);
  }

  cout << op << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
