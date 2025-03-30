#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  bool keys = false, phone = false, wallet = false;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    if (s == "keys") keys = true;
    else if (s == "phone") phone = true;
    else if (s == "wallet") wallet = true;
  }

  if (!keys) cout << "keys" << endl;
  if (!phone) cout << "phone" << endl;
  if (!wallet) cout << "wallet" << endl;
  if (keys && phone && wallet) cout << "ready" << endl;
  return 0;
}
