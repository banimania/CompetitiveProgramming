#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (isalpha(s[i])) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
