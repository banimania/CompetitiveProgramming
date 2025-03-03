#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    a[i] = n - a[i];
  }
  sort(a.begin(), a.end());
  vector<ll> pSum(k);
  pSum[0] = a[0];
  for (int i = 1; i < k; i++) {
    pSum[i] = pSum[i - 1] + a[i];
  }

  auto lb = lower_bound(pSum.begin(), pSum.end(), n);
  cout << lb - pSum.begin() << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
