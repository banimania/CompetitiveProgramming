#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int n = stoi(s.substr(0, 2));
    
    int op;
    if (n > 18) {
      n -= 18;
    } else {
      n += 18;
    }

    // cout << setw(2) << setfill('0') << n;
    if (n < 10) cout << 0;
    cout << n;

    if (s.size() == 3) {
      if (s[2] == 'C') cout << 'C';
      else if (s[2] == 'R') cout << 'L';
      else cout << 'R';
    }

    cout << "\n";
  }
  return 0;
}
