#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    int x = stoi(s.substr(max(0, (int) s.size() - 4)));

    int mod16 = x % 16;

    if (mod16 == 0 || mod16 == 1 || mod16 == 4 || mod16 == 9) {
      cout << "NO SE\n";
    } else {
      cout << "IMPERFECTO\n";
    }
  }

  return 0;
}
