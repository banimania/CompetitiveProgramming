#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> dirs = {{'N', {-1, 0}}, {'S', {1, 0}}, {'E', {0, 1}}, {'O', {0, -1}}};
int main() {
  int n;
  while (cin >> n && n) {
    int cI = 0, cJ = 0;
    int minI = 0, maxI = 0, minJ = 0, maxJ = 0;
    vector<pair<int, char>> mp(n);
    set<pair<int, int>> visited;
    for (int i = 0; i < n; i++) {
      cin >> mp[i].first >> mp[i].second;

      int dI = dirs[mp[i].second].first;
      int dJ = dirs[mp[i].second].second;

      for (int j = 0; j < mp[i].first; j++) {
        cI += dI;
        cJ += dJ;
        visited.insert({cI, cJ});
      }

      minI = min(cI, minI);
      maxI = max(cI, maxI);
      minJ = min(cJ, minJ);
      maxJ = max(cJ, maxJ);
    }

    int w = maxI - minI + 1, h = maxJ - minJ + 1;

    for (int i = 0; i < h + 2; i++) cout << '#';
    cout << endl;
    
    for (int i = minI; i <= maxI; i++) {
      cout << '#';
      for (int j = minJ; j <= maxJ; j++) {
        if (i == 0 && j == 0) cout << 'O';
        else if (i == cI && j == cJ) cout << 'F';
        else cout << (visited.count({i, j}) ? '.' : ' ');
      }
      cout << '#' << endl;
    }
    
    for (int i = 0; i < h + 2; i++) cout << '#';
    cout << endl << endl;
  }
  return 0;
}
