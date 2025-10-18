#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>

#define ll long long

using namespace std;

void solve() {
  ll n, k;
  cin >> n >> k;
  uint32_t mask = (1U << k) - 1;

  vector<pair<uint32_t, ll>> a;
  for (ll i = 0; i < n; i++) {
    uint32_t x;
    cin >> x;
    a.push_back({x, i+1});
  }

  sort(a.begin(), a.end());

  ll maxValue = 0;
  ll index = -1;
  for (ll i = 0; i < n-1; i++) {
    uint32_t value = ~(a[i].first ^ a[i+1].first) & mask;
    if (value >= maxValue) {
      maxValue = value;
      index = i;
    }
  }

  uint32_t x = ~(a[index].first & a[index+1].first) & mask;
  cout << a[index].second << " " << a[index+1].second << " " << x << "\n";



  return;
}

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
