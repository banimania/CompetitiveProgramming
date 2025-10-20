#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    string aux;
    for (int i = 0; i < s.size(); i++) {
      aux.push_back(isupper(s[i]) ? toupper(s[s.size() - 1 - i]) : tolower(s[s.size() - 1 - i]));
    }

    cout << aux << "\n";
  }
  return 0;
}
