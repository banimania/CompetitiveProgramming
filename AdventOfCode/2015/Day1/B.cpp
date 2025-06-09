#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int bal = 1;

  int i = 0;
  for (; i < s.size() && bal; i++) {
    bal += (s[i] == '(' ? 1 : -1);
  }

  cout << i << endl;
  return 0;
}
