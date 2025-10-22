#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  while (cin >> str) {
    int ans = str.size();
    for (int i = 0; i < str.size(); i++) str[i] = tolower(str[i]);
    for (int i = 1; i <= str.size(); i++) {
      if (str.size() % i) continue;

      bool works = true;
      for (int j = i; j < str.size(); j++) {
        if (str[j] != str[j % i]) {
          works = false;
          break;
        }
      }

      if (works) {
        ans = i;
        break;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
