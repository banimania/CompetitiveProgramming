#include <bits/stdc++.h>
using namespace std;

void inc(string &s, int pos, int np) {
  if (pos == -1) {
    if (np == 3) s = "1." + s;
    else s = "1" + s;
    return;
  }
  if (s[pos] == '.') {
    inc(s, pos - 1, 0);
    return;
  }
  if (s[pos] == '9') {
    s[pos] = '0';
    inc(s, pos - 1, np + 1);
    return;
  }

  s[pos]++;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  while (getline(cin, s)) {
    inc(s, s.size() - 1, 0);

    cout << s << "\n";
  }

  return 0;
}
