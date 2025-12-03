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

    if (dir == 'L') {
      curr = (100 + (curr - amount) % 100) % 100;
    } else {
      curr = (100 + (curr + amount) % 100) % 100;
    }

    if (!curr) ans++;
  }

  cout << ans << "\n";

  return 0;
}
