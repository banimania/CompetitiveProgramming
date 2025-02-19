#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b) {
    if (a == b) {
      cout << 0 << endl;
      continue;
    }
    queue<int> q;
    vector<int> bestDist(10000, INT_MAX);
    bestDist[a] = 0;
    q.push(a);
    while (!q.empty()) {
      int actual = q.front();
      q.pop();

      if (actual == b) {
        break;
      }
      int plusOne = (10000 + ((actual + 1) % 10000)) % 10000;
      int dividedTwo = (actual * 2) % 10000;
      int timesThree = (actual / 3) % 10000;

      if (bestDist[actual] + 1 < bestDist[plusOne]) {
        bestDist[plusOne] = bestDist[actual] + 1;
        q.push(plusOne);
      }
      if (bestDist[actual] + 1 < bestDist[dividedTwo]) {
        bestDist[dividedTwo] = bestDist[actual] + 1;
        q.push(dividedTwo);
      }
      if (bestDist[actual] + 1 < bestDist[timesThree]) {
        bestDist[timesThree] = bestDist[actual] + 1;
        q.push(timesThree);
      }
    }
    cout << bestDist[b] << endl;
  }
  return 0;
}
