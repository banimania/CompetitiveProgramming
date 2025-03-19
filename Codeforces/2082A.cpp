#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }

  int f1 = 0, f2 = 0;
  
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < m; j++) {
      s += (a[i][j] == '1');
    }
    f1 += (s % 2);
  }
  
  for (int j = 0; j < m; j++) {
    int s = 0;
    for (int i = 0; i < n; i++) {
      s += (a[i][j] == '1');
    }
    f2 += (s % 2);
  }

  cout << max(f1, f2) << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
