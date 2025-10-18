#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;

  int t;
  cin >> t;
  while (t--) {
    int d = -1;
    int t = -1;
    int v = -1;

    cin >> s;

    if (s[0] == 'D') {
      d = stoi(s.substr(2, s.size() - 2));
    }
    if (s[0] == 'T') {
      t = stoi(s.substr(2, s.size() - 2));
    }
    if (s[0] == 'V') {
      v = stoi(s.substr(2, s.size() - 2));
    }

    cin >> s;

    if (s[0] == 'D') {
      d = stoi(s.substr(2, s.size() - 2));
    }
    if (s[0] == 'T') {
      t = stoi(s.substr(2, s.size() - 2));
    }
    if (s[0] == 'V') {
      v = stoi(s.substr(2, s.size() - 2));
    }

    if (v == -1) {
      v = d / t;
      cout << "V=" << v << '\n';
    }

    if (t == -1) {
      t = d / v;
      cout << "T=" << t << '\n';
    }

    if (d == -1) {
      d = v * t;
      cout << "D=" << d << '\n';
    }
  }
  return 0;
}
