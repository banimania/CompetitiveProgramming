#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int bars = 0;
  int i = 0;
  for (; s[i] != '('; i++) {
    if (s[i] == '|') bars++;
  }

  i++;
  for (; i < s.size(); i++) {
    if (s[i] == '|') bars--;
  }

  cout << (bars ? "fix" : "correct") << endl;

  return 0;
}
