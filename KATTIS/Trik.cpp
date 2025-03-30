#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<bool> cups(3);
  cups[0] = 1;
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A') {
      swap(cups[0], cups[1]);
    } else if (s[i] == 'B') {
      swap(cups[1], cups[2]);
    } else {
      swap(cups[0], cups[2]);
    }
  }

  for (int i = 0; i < cups.size(); i++) {
    if (cups[i]) {
      cout << i + 1 << endl;
      break;
    }
  }
  return 0;
}
