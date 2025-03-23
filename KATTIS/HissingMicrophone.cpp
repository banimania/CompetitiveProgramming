#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  bool hiss = false;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 's' && s[i] == s[i - 1]) {
      hiss = true;
      break;
    }
  }
  cout << (hiss ? "hiss" : "no hiss") << endl;
  return 0;
}
