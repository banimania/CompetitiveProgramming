#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  while (getline(cin, s)) {
    int normal = 0, exclamacion = 0;

    for (int i = 0; i < s.size(); i++) {
      if (isalpha(s[i])) normal++;
      else if (s[i] == '!') exclamacion++;
    }

    cout << (exclamacion > normal ? "ESGRITO" : "escrito") << "\n";
  }

  return 0;
}
