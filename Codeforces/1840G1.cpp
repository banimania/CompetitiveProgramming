#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  map<int, int> mp;
  int x;
  cin >> x;
  mp[x] = 0;

  for (int i = 1; i <= 1000; i++) {
    cout << "+ 1" << endl;
    cin >> x;

    if (mp.count(x)) {
      cout << "! " << i << endl;
      return 0;
    }

    mp[x] = i;
  }

  for (int i = 1; ; i++) {
    cout << "+ 1000" << endl;
    cin >> x;

    if (mp.count(x)) {
      cout << "! " << (i + 1) * 1000 - mp[x] << endl;
      return 0;
    }

    mp[x] = (i + 1) * 1000;
  }

  return 0;
}
