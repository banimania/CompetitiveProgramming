#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n && n) {
    unordered_set<string> s;
    bool ans = false;
    string str;
    for (int i = 0; i < n; i++) {
      cin >> str;

      bool seen = false;
      string aux = "";
      for (int j = 0; j < str.size(); j++) {
        if (str[j] == '/') {
          if (seen) break;
          else aux += str[j];
          seen = true;
        } else {
          aux += str[j];
        }
      }
      if (s.count(aux)) ans = true;
      s.insert(aux);
    }
    cout << (ans ? "SI" : "NO") << "\n";
  }
  return 0;
}
