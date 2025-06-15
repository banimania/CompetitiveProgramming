#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  while (getline(cin, s)) {
    int ans = 0;
    stack<char> p;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '@') {
        p = stack<char>();
      } else if (tolower(s[i]) == 'h') {
        p.push(s[i]);
      } else if (tolower(s[i]) == 'm') {
        if (!p.empty() && tolower(p.top()) == 'h' && isupper(s[i]) == isupper(p.top())) {
          ans++;
          p.pop();
        } else p.push(s[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
