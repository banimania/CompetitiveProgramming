#include <bits/stdc++.h>
using namespace std;

void fillStr(string &a, int n) {
  while (a.size() < n) {
    a = '0' + a;
  }
}

int main() {
  string a, b, c;
  while (cin >> a >> b >> c) {
    int maxLen = max({a.size(), b.size(), c.size()});
    fillStr(a, maxLen);
    fillStr(b, maxLen);
    fillStr(c, maxLen);
    vector<map<char, int>> digits(maxLen);

    for (int i = a.size() - 1; i >= 0; i--) {
      digits[i][a[i]]++;
    }

    for (int i = b.size() - 1; i >= 0; i--) {
      digits[i][b[i]]++;
    }

    for (int i = c.size() - 1; i >= 0; i--) {
      digits[i][c[i]]++;
    }

    bool ruido = false;
    string ans = string(maxLen, '0');

    for (int i = 0; i < maxLen && !ruido; i++) {
      bool found = false;
      for (const pair<char, int> &p : digits[i]) {
        if (p.second >= 2) {
          ans[i] = p.first;
          found = true;
          break;
        }
      }

      if (!found) ruido = true;
    }

    cout << (ruido ? "RUIDO COSMICO" : to_string(stoi(ans))) << endl;
  }
  return 0;
}
