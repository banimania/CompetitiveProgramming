#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    if (s == "00:00") break;

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    cout << (1440 - (h * 60 + m)) << "\n";
  }
  return 0;
}

