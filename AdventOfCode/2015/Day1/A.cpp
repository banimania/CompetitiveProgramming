#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int bal = 0;

  for (int i = 0; i < s.size(); i++) {
    bal += (s[i] == '(' ? 1 : -1);
  }

  cout << bal << endl;
  return 0;
}
