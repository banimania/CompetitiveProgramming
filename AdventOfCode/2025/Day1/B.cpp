#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  ll ans = 0;

  ll curr = 50;
  string line;
  while (getline(cin, line)) {
    char dir = line[0];

    int amount = stoi(line.substr(1, line.size() - 1));

    int left = amount;
    if (dir == 'L') {
      while (left) {
        left--;
        curr = (100 + (curr - 1) % 100) % 100;
        if (curr == 0) ans++;
      }
    } else {
      while (left) {
        left--;
        curr = (100 + (curr + 1) % 100) % 100;
        if (curr == 0) ans++;
      }
    }

  }

  cout << curr << endl;
  cout << ans << "\n";

  return 0;
}
