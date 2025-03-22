#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string current = "";
  for (int i = 0; i < n; i++) {
    string meat;
    cin >> meat;

    if (current.empty()) current = meat;
    else if (current != meat) current = "blandad best";
  }

  cout << current << endl;
  return 0;
}
