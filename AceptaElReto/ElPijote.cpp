#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  while (cin >> s) {
    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++) {
      freq[s[i] - '0']++;
    }

    bool ans = true;

    for (int i = 1; i <= 9; i++) {
      if (freq[i] != freq[0]) {
        ans = false;
        break;
      }
    }
    cout << (ans ? "subnormal" : "no subnormal") << "\n";
  }

  return 0;
}
