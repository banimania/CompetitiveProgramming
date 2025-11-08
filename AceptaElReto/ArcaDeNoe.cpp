#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  while (cin >> n && n) {
    int sobran = 0;
    unordered_map<string, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
      string str;
      cin >> str;

      char term = str.back();
      str = str.substr(0, str.size() - 1);


      if (term == 'a') {
        if (mp[str].first == 1) sobran++;
        else mp[str].first++;
      } else {
        if (mp[str].second == 1) sobran++;
        else mp[str].second++;
      }
    }

    int completas = 0;
    int incompletas = 0;
    for (const pair<string, pair<int, int>> &par : mp) {
      // cout << par.first << " " << par.second.first << " " << par.second.second << endl;
      completas += min(par.second.first, par.second.second);

      incompletas += max(par.second.first, par.second.second) - min(par.second.first, par.second.second);
    }

    cout << completas << " " << incompletas << " " << sobran << "\n";
  }
  return 0;
}
