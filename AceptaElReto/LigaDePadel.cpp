#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  string cat;
  while (cin >> cat) {
    if (cat == "FIN") break;

    string eq1, eq2;
    int p1, p2;
    int j = 0;

    unordered_map<string, int> pts;

    while (cin >> eq1) {
      if (eq1 == "FIN") break;

      cin >> p1 >> eq2 >> p2;

      if (p1 > p2) {
        pts[eq1] += 2;
        pts[eq2]++;
      } else {
        pts[eq1]++;
        pts[eq2] += 2;
      }
      j++;
    }

    string ans = "EMPATE";
    int maxPts = INT_MIN;

    for (const pair<string, int> &p : pts) {
      if (p.second > maxPts) {
        maxPts = p.second;
        ans = p.first;
      } else if (p.second == maxPts) {
        ans = "EMPATE";
      }
    }

    int l = pts.size() * (pts.size() - 1) - j;
    cout << ans << " " << l << '\n';
  }
  return 0;
}
