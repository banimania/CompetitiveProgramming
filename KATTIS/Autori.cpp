#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  string a;
  for (int i = 0; i < s.size(); i++) {
    if (i == 0 || s[i] == '-') {
      a += s[i + 1 - (i == 0)];
    }
  }

  cout << a << endl;
  return 0;
}
