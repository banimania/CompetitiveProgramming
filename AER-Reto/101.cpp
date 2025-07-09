#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
}

int main() {
  int n;
  while (cin >> n && n) {
    vector<vector<int>> a(n, vector<int>(n));

    int sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        sum += a[i][j];
      }
    }

    int cm = 0;
    for (int i = 0; i < n; i++) {
      cm += a[i][0];
    }

    bool checkSum = true;
    for (int i = 0; i < n && checkSum; i++) {
      int currRow = 0;
      int currCol = 0;

      for (int j = 0; j < n; j++) {
        currRow += a[i][j];
        currCol += a[j][i];
      }

      if (currRow != cm || currCol != cm) checkSum = false;
    }

    int curr = 0;
    for (int i = 0; i < n && checkSum; i++) {
      curr += a[i][i];
    }
    if (curr != cm) checkSum = false;

    for (int i = 1; i < n && checkSum; i++) {
      int currUp = 0;
      int currDown = 0;

      for (int j = 0; i + j < n; j++) {
        currUp += a[i + j][j];
        currDown += a[j][i + j];
      }

      if (currUp != cm || currDown != cm) checkSum = false;
    }

    if (!checkSum) {
      cout << "NO" << endl;
      continue;
    }
    
    if (sum != n * (n + 1) / 2) {


    }
  }

  return 0;
}
