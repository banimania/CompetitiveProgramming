#include <bits/stdc++.h>
using namespace std;

int casillas(int height, vector<vector<int>> &heights, int f, int c) {
  int ans = 1;
  stack<pair<int, int>> st;
  vector<vector<bool>> visitados(f, vector<bool>(c));

  st.push({f / 2, 0});
  visitados[f / 2][0] = true;

  while (!st.empty()) {
    pair<int, int> curr = st.top();
    st.pop();
    int i = curr.first;
    int j = curr.second;

    for (int deltaI = -1; deltaI <= 1; deltaI++) {
      if (!deltaI) continue;
      int newI = i + deltaI;
      int newJ = j;

      if (newI >= 0 && newI < f && newJ >= 0 && newJ < c && !visitados[newI][newJ] && heights[newI][newJ] <= height) {
        visitados[newI][newJ] = true;
        st.push({newI, newJ});
        ans++;
      }
    }

    for (int deltaJ = -1; deltaJ <= 1; deltaJ++) {
      if (!deltaJ) continue;
      int newI = i;
      int newJ = j + deltaJ;

      if (newI >= 0 && newI < f && newJ >= 0 && newJ < c && !visitados[newI][newJ] && heights[newI][newJ] <= height) {
        visitados[newI][newJ] = true;
        st.push({newI, newJ});
        ans++;
      }

    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c, f;
  while (cin >> c >> f) {
    vector<vector<int>> heights(f, vector<int>(c));

    int maxH = 0;
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        cin >> heights[i][j];
        maxH = max(maxH, heights[i][j]);
      }
    }

    int high = maxH, low = 0;
    int ans = 0, ansC = 0;
    
    int mitad = (f * c) / 2;
    while (high >= low) {
      int mid = (high - low) / 2 + low;
      int val = casillas(mid, heights, f, c);
      if (val > mitad) {
        high = mid - 1;
        ans = mid;
        ansC = val;
      } else {
        low = mid + 1;
      }
    }
    cout << ans << " " << ansC << "\n";
  }
  return 0;
}
