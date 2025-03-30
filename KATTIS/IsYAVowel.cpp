#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt = 0, cntY = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i') cnt++;
    else if (s[i] == 'y') cntY++;
  }
  
  cout << cnt << " " << cnt + cntY << endl;

  return 0;
}
