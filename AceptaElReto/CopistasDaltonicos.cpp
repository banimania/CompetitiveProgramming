#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    if (!n && !m) break;

    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }

    map<char, char> replacement;
    for (char i = 'A'; i <= 'Z'; i++) {
      replacement[i] = i;
    }

    int x;
    cin >> x;

    for (int i = 0; i < x; i++) {
      char o, d;
      cin >> o >> d;
      for (char i = 'A'; i <= 'Z'; i++) {
        if (replacement[i] == o) replacement[i] = d;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << replacement[a[i][j]];
      }
      cout << endl;
    }
  }

  return 0;
}
