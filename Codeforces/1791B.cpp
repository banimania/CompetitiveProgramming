#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
  ll n;
  string s;
  cin >> n;
  cin >> s;

  pair<int, int> pos = {0, 0}, candy = {1, 1};
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U') {
      pos.second++;
    } else if (s[i] == 'D') {
      pos.second--;
    } else if (s[i] == 'R') {
      pos.first++;
    } else {
      pos.first--;
    }

    if (pos == candy) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
