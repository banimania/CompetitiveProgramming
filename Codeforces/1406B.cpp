#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  bool allNeg = true;
  ll zeros = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];

    if (v[i] > 0) {
      allNeg = false;
    } else if (v[i] == 0) zeros++;
  }

  ll product = 1;
  if (allNeg) {
    sort(v.begin(), v.end(), [](const ll &a, const ll &b) {
      return a > b;
    });

    for (int i = 0; i < 5; i++) {
      product *= v[i];
    }

    cout << product << endl;
    return;
  }

  sort(v.begin(), v.end(), [](const ll &a, const ll &b) {
    return abs(a) > abs(b);
  });

  for (int i = 0; i < 5; i++) {
    product *= v[i];
  }

  for (int i = 5; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      ll tmp = v[i];
      for (int k = 0; k < 5; k++) {
        if (k != j) tmp *= v[k];
      }
      product = max(product, tmp);
    }
  }

  cout << product << endl;
}

int main() {
  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
