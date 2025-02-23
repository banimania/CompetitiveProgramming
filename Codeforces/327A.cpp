#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int bestI = -1, bestJ = -1, bestSum = INT_MIN;
  int currentI = 0, currentJ = 0, currentSum = 0;
  int ones = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    if (x) ones++, x = -1;
    else x = 1;

    if (x > currentSum) {
      currentSum = x;
      currentI = i;
    } else currentSum += x;

    currentJ = i;

    if (currentSum > bestSum) {
      bestSum = currentSum;
      bestI = currentI;
      bestJ = currentJ;
    }
  }

  cout << ones + bestSum << endl;
  return 0;
}
