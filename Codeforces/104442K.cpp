#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

void solve() {
  ll n;
  cin >> n;
  
  ll n1 = n - 1LL;
  ll n2 = (1LL << 32);
  
  cout << __gcd(n1, n2) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
