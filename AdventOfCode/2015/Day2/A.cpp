#include <bits/stdc++.h>
using namespace std;

int main() {
  string line;
  int ans = 0;

  while (getline(cin, line)) {
    istringstream iss(line);

    string lStr, wStr, hStr;

    getline(iss, lStr, 'x');
    getline(iss, wStr, 'x');
    getline(iss, hStr, 'x');

    int l = stoi(lStr), w = stoi(wStr), h = stoi(hStr);

    ans += (2 * l * w) + (2 * w * h) + (2 * h * l) + min({l * w, w * h, h * l});
  }

  cout << ans << endl;

  return 0;
}
