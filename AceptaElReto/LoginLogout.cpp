#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int maximum = 0;
    int minimum = 0;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'I') {
        cnt++;
      } else if (s[i] == 'O') {
        cnt--;
      }

      maximum = max(maximum, cnt);
      minimum = min(minimum, cnt);
    }

    cout << maximum - minimum << '\n';
  }

  return 0;
}
