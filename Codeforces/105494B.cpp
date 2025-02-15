#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  
  ll ans = 0;
  ll sum = 0;
  
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    
    sum += x;
    
    if (sum < 0) {
      ans = max(ans, abs(sum));
    }
  }
  
  cout << ans << endl;
  return 0;
}
