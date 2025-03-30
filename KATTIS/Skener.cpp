#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, c, zr, zc;
  cin >> r >> c >> zr >> zc;

  vector<vector<char>> a;
  for (int i = 0; i < r; i++) {
    vector<char> row;
    for (int j = 0; j < c; j++) {
      char x;
      cin >> x;

      for (int k = 0; k < zc; k++) row.push_back(x);
    }

    for (int k = 0; k < zr; k++) a.push_back(row);
  }

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < a[0].size(); j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
