#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = i * m + j + 1;
      }
    }

    vector<vector<int>> b(n);
    
    int cnt = 0;

    for (int i = 0; 2 * i + 1 < n; i++) {
      b[cnt++] = a[2 * i + 1];
    }

    for (int i = 0; 2 * i < n; i++) {
      b[cnt++] = a[2 * i];
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << b[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
