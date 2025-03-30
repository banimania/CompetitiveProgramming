#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> freqX, freqY;
  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    freqX[x]++, freqY[y]++;
  }

  int fx, fy;
  for (auto [x, num] : freqX) {
    if (num != 2) {
      fx = x;
      break;
    }
  }
  for (auto [y, num] : freqY) {
    if (num != 2) {
      fy = y;
      break;
    }
  }
  cout << fx << " " << fy << endl;
  return 0;
}
