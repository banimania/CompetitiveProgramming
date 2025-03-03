#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  string s;
  cin >> s;

  ll ans = 0;
  ll ones = 0;
  ll zeros = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      if (ones && zeros) {
        ans += (ones + 1) * (zeros);

        zeros = 0;
      }
      ones++;
    } else {
      if (ones) zeros++;
    }
    
  }

  bool sorted = true;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == '0' && s[i - 1] == '1') {
      sorted = false;
      break;
    }
  }

  if (!sorted) ans += (ones + 1) * (zeros);

  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
