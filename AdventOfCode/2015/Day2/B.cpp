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

    ans += min({2 * l + 2 * w, 2 * w + 2 * h, 2 * h + 2 * l}) + l * w * h;
  }

  cout << ans << endl;

  return 0;
}
