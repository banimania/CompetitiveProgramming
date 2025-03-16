#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> comb(11, vector<int>(11));
  for (int i = 0; i <= 10; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) comb[i][j] = 1;
      else if (i == 0) comb[i][j] = 0;
      else {
        comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
      }
    }
  }

  string s1, s2;
  cin >> s1 >> s2;

  int suma1 = 0, suma2 = 0;
  for (int i = 0; i < s1.size(); i++) {
    suma1 += (s1[i] == '+' ? 1 : 0);
    suma2 += (s2[i] == '+' ? 1 : 0);
  }

  int nq = 0;
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] == '?') {
      nq++;
    }
  }

  int dif = suma1 - suma2;

  double ans = 0;
  if (nq < dif || dif < 0) {
    ans = 0;
  } else {
    ans = (double) comb[nq][dif] / (1 << nq);
  }
  cout << fixed << setprecision(9) << ans << endl;
  return 0;
}
