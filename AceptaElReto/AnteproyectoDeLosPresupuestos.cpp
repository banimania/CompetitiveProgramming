#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll dinero, ll n) {
  ll w[n];
  for (ll i = 0; i < n; i++) {
    cin >> w[i];
  }

  sort(w, w + n);

  ll res = 0;
  ll acc = 0;

  for (ll i = 0; i < n; i++) {
    if (acc + w[i] + w[i] * (n - i - 1) <= dinero) {
      acc += w[i];
      res = w[i];
    } else {
      res = (dinero - acc) / (n - i);
      break;
    }
  }

  cout << res << "\n";

}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll dinero, n;
  while (cin >> dinero >> n) {
    solve(dinero, n);
  }
}
