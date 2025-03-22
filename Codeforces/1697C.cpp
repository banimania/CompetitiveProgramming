#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  string s, t;
  map<char, int> freq1, freq2;
  cin >> n >> s >> t;

  for (int i = 0; i < n; i++) freq1[s[i]]++;
  for (int i = 0; i < n; i++) freq2[t[i]]++;

  if (freq1['b'] != freq2['b']) {
    cout << "NO" << endl;
    return;
  }

  int j = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b') continue;
    while (t[j] == 'b') j++;

    if (s[i] != t[j] || (s[i] == 'a' && i > j) || (s[i] == 'c' && i < j)) {
      cout << "NO" << endl;
      return;
    }
    j++;
  }

  cout << "YES" << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
