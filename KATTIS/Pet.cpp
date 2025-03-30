#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> sum(5);
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 4; j++) {
      int x;
      cin >> x;

      sum[i] += x;
    }
  }

  int winner = 0;
  for (int i = 1; i < 5; i++) {
    if (sum[i] > sum[winner]) {
      winner = i;
    }
  }

  cout << winner + 1 << " " << sum[winner] << endl;
  return 0;
}
