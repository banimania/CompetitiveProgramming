#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  while (cin >> n && n) {
    string s;
    while (n > 0) {
      s.push_back((n % 2) + '0');
      n /= 2;
    }

    int first = 0, last = n - 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '1') break;
      first++;
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '1') break;
      last--;
    }

    s = s.substr(first, last - first);

    bool palindromo = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != s[s.size() - i - 1]) {
        palindromo = false;
        break;
      }
    }

    cout << (palindromo ? "SI" : "NO") << endl;
  }
  return 0;
}
