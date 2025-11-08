#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    ll ans = 0;
    ll curr = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'O') {
        curr++;
        ans += curr * 10;
      } else {
        curr = 0;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
