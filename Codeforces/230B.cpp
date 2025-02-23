#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef vector<ll> vll;

#define TESTCASES 0

void solve() {
  vector<ll> primes(1000005, true);

  for (ll i = 2; i < primes.size(); i++) {
    if (primes[i]) {
      for (ll j = i * i; j < primes.size(); j += i) {
        primes[j] = false;
      }
    }
  }

  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];

    double rt = sqrt(a[i]);
    if (a[i] != 1 && rt == (ll) rt && primes[(ll) rt]) {
      cout << "YES" << endl;
      continue;
    } 
    cout << "NO" << endl;
  }
}

int main(){
  int t = 1;
  if (TESTCASES) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
