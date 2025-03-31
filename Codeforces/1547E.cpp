#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, k;
  cin >> n >> k;

  map<ll, ll> air;
  vector<ll> pos(k), temp(k);
  for (int i = 0; i < k; i++) cin >> pos[i];
  for (int i = 0; i < k; i++) cin >> temp[i];

  for (int i = 0; i < k; i++) {
    air[pos[i] - 1] = temp[i];
  }

  vector<ll> right(n);
  ll best = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (air.count(i)) best = min(best, air[i]);

    right[i] = best;

    best++;
  }
  
  vector<ll> left(n);
  best = INT_MAX;
  for (int i = n - 1; i >= 0; i--) {
    if (air.count(i)) best = min(best, air[i]);

    left[i] = best;

    best++;
  }

  for (int i = 0; i < n; i++) {
    cout << min(left[i], right[i]) << " ";
  }
  cout << endl;
}

int main() {
  int q;
  cin >> q;
  while (q--) solve();
  return 0;
}
