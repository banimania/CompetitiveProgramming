#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  for (int i = 1; i < (s.size() + 1) / 2; i++){
    bool possible = true;
    for (int j = i; j < s.size(); j++){
      if (s[j-i] == s[j]) continue;
      possible = false;
      break;
    }

    if (possible) {
      cout << "YES" << endl;
      for (int j = i; j < s.size(); j++) cout << s[j];
      cout << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
