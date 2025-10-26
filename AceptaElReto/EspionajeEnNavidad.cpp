#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  string s;
  while (getline(cin, s)) {
    if (s == "FIN") {
      break;
    }

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') cout << ' ';
      else cout << (char) ((s[i] - 'A' + 1) % 26 + 'A');
    }
    cout << "\n";
  }
  return 0;
}
