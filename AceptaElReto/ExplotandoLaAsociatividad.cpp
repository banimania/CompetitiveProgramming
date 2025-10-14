#include <bits/stdc++.h>
using namespace std;

static int dpMin[102][102];
static int dpMax[102][102];
static int sizes[102];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  for (int i = 0; i < 102; ++i) {
    dpMin[i][i] = 0;
    dpMax[i][i] = 0;
  }

  int n;
  while (cin >> n) {
    for (int i = 0; i < n + 1; ++i) {
      cin >> sizes[i];
    }

    for (int len = 2; len <= n; ++len) {
      for (int i = 0; i <= n - len; ++i) {
        int j = len + i - 1;
        dpMin[i][j] = INT_MAX;
        dpMax[i][j] = INT_MIN;

        int l = sizes[i], r = sizes[j + 1], c = l * r;
        for (int k = i; k < j; ++k) {
          const int cost = sizes[k + 1] * c;
          dpMin[i][j] = min(dpMin[i][j], dpMin[i][k] + dpMin[k + 1][j] + cost);
          dpMax[i][j] = max(dpMax[i][j], dpMax[i][k] + dpMax[k + 1][j] + cost);
        }
      }
    }
    cout << dpMin[0][n - 1] << " " << dpMax[0][n - 1] << '\n';
  }
  return 0;
}
