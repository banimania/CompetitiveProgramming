#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    vector<int> sides(3);
    cin >> sides[0] >> sides[1] >> sides[2];
    sort(sides.begin(), sides.end());

    bool possible = (sides[0] + sides[1] > sides[2] && sides[2] + sides[0] > sides[1] && sides[2] + sides[1] > sides[0]);

    if (!possible) {
      cout << "IMPOSIBLE" << endl;
      continue;
    }

    int a2pb2 = sides[0] * sides[0] + sides[1] * sides[1];
    int c2 = sides[2] * sides[2];
    if (a2pb2 == c2) {
      cout << "RECTANGULO" << endl;
    } else if (a2pb2 < c2) {
      cout << "OBTUSANGULO" << endl;
    } else {
      cout << "ACUTANGULO" << endl;
    }
  }
  return 0;
}
