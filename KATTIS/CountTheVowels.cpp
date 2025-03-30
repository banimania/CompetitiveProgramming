#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  getline(cin, s);

  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    char x = tolower(s[i]);

    if (x == 'a' || x == 'e' || x == 'i' || x == 'u' || x == 'o') cnt++;
  }

  cout << cnt << endl;

  return 0;
}
