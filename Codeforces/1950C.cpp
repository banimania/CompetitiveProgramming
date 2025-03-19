#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string clock;
    cin >> clock;

    int h = stoi(clock.substr(0, 2));
    int m = stoi(clock.substr(3, 2));

    bool pm = h >= 12;
    if (h == 0) h = 12;
    if (h > 12) h -= 12;

    string hs = (h < 10 ? "0" : "") + to_string(h);
    string ms = (m < 10 ? "0" : "") + to_string(m);

    cout << hs << ":" << ms << " " << (pm ? "PM" : "AM") << endl;
  }
  return 0;
}
