#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    int p, n;
    cin >> p >> n;

    int start = 0, distStart = INT_MAX;
    vector<int> portales(n);
    for (int i = 0; i < n; i++) {
      cin >> portales[i];
      int currDist = abs(p - portales[i]);
      if (distStart > currDist || (distStart == currDist && portales[i] > start)) {
        distStart = currDist;
        start = portales[i];
      }
    }
    sort(portales.begin(), portales.end());

    int startI = lower_bound(portales.begin(), portales.end(), start) - portales.begin();

    cout << portales[startI];

    int nextL = startI - 1, nextR = startI + 1;

    int curr = startI;
    while (nextL != -1 || nextR != n) {
      if (nextL == -1) {
        cout << " " << portales[nextR];
        curr = nextR;
        nextR++;
      } else if (nextR == n) {
        cout << " " << portales[nextL];
        curr = nextL;
        nextL--;
      } else {
        int distL = portales[curr] - portales[nextL];
        int distR = portales[nextR] - portales[curr];

        if (distL < distR) {
          cout << " " << portales[nextL];
          curr = nextL;
          nextL--;
        } else {
          cout << " " << portales[nextR];
          curr = nextR;
          nextR++;
        }
      }
    }

    cout << "\n";
  }

  return 0;
}
