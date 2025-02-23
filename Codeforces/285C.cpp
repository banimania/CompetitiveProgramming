#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;

#define TESTCASES 0

void solve() {
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs((i + 1) - a[i]);
  }

  cout << ans << endl;
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
