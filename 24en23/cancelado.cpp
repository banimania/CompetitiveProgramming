#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    cin.ignore();
    string first;
    getline(cin, first);
    vector<vector<char>> grid(m, vector<char>(n));

    for (int i = 0; i < m; i++) {
      string s;
      getline(cin, s);
      s = s.substr(1, s.size() - 2);
      for (int j = 0; j < s.size(); j++) grid[i][j] = s[j];
    }
    getline(cin, first);

    for (int i = 0; i < m + 2; i++) cout << '-';
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
      cout << '|';
      for (int j = 0; j < m; j++) cout << grid[j][i];
      cout << '|' << endl;
    }
    for (int i = 0; i < m + 2; i++) cout << '-';
    cout << endl;
  }

  return 0;
}
