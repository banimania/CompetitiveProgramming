#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  cin.ignore();
  string s;
  while (n--) {
    getline(cin, s);

    if (s.substr(0, 10) == "Simon says") cout << s.substr(10, s.size() - 10) << endl;
  }
  return 0;
}
