#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n;
  string s;
  cin >> n >> s;

  vector<ll> difChar1(n);
  set<char> seen;
  for (int i = 0; i < n; i++) {
    if (!seen.count(s[i])) {
      seen.insert(s[i]);
      difChar1[i]++;
    }
    if (i != 0) difChar1[i] += difChar1[i - 1];
  }

  seen.clear();
  vector<ll> difChar2(n);
  for (int i = n - 1; i >= 0; i--) {
    if (!seen.count(s[i])) {
      seen.insert(s[i]);
      difChar2[i]++;
    }
    if (i != n - 1) difChar2[i] += difChar2[i + 1];
  }

  ll ans = 0;

  for (int i = 1; i < n; i++) {
    ans = max(ans, difChar1[i - 1] + difChar2[i]);
  }
  
  for (int i = 0; i < n - 1; i++) {
    ans = max(ans, difChar1[i] + difChar2[i + 1]);
  }

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
