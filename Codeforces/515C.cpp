#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> factors(10);
  for (int i = 0; i < s.size(); i++) {
    int x = s[i] - '0';
    if (x <= 1) continue;

    if (x == 9) {
      factors[7]++;
      factors[3] += 2;
      factors[2]++;
    } else if (x == 8) {
      factors[2] += 3;
      factors[7]++;
    } else if (x == 6) {
      factors[5]++;
      factors[3]++;
    } else if (x == 4) {
      factors[2] += 2;
      factors[3]++;
    } else {
      factors[x]++;
    }
  }

  string ans;
  for (int i = 9; i >= 0; i--) {
    for (int j = 0; j < factors[i]; j++) ans += ('0' + i);
  }

  cout << ans << endl;
}

int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
