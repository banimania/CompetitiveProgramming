#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> m >> n;
  int e = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;

      if (x == '.') e++;
    }
  }

  cout << fixed << setprecision(6) << (e / (double)(n * m)) << endl;
}
