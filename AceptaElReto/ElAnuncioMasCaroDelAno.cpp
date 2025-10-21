#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;

    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int s = stoi(str.substr(6, 2));

    int mom = h * 60 * 60 + m * 60 + s;

    int ans = 24 * 60 * 60 - mom;

    int ha = ans / 3600;
    int ma = (ans / 60) % 60;
    int sa = ans % 60;

    cout << setw(2) << setfill('0') << ha << ":" << setw(2) << setfill('0') <<  ma << ":" << setw(2) << setfill('0') << sa << "\n";
  }

  return 0;
}
