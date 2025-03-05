#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int main() {
  int nBarcos;
  while (cin >> nBarcos && nBarcos) {
    multiset<int> tBarcos;
    for (int i = 0; i < nBarcos; i++) {
      int x;
      cin >> x;
      tBarcos.insert(x);
    }

    int n;
    cin >> n;
    vector<vector<bool>> tablero(n, vector<bool>(n));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        cin >> x;

        tablero[i][j] = x;
      }
    }

    bool posible = true;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (tablero[i][j]) {
          int size = 1;
          stack<pair<int, int>> st;
          st.push({i, j});
          tablero[i][j] = false;

          while (!st.empty()) {
            pair<int, int> curr = st.top();
            st.pop();

            for (pair<int, int> dir : dirs) {
              int newI = curr.first + dir.first;
              int newJ = curr.second + dir.second;

              if (newI >= 0 && newI < n && newJ >= 0 && newJ < n && tablero[newI][newJ]) {
                tablero[newI][newJ] = false;
                st.push({newI, newJ});
                size++;
              }
            }
          }

          auto it = tBarcos.find(size);

          if (it == tBarcos.end()) {
            posible = false;
            break;
          } else {
            tBarcos.erase(it);
          }
          // demasiado moderno para aceptaelreto xd
          // if (!tBarcos.count(size)) {
          //   posible = false;
          //   break;
          // } else {
          //   tBarcos.extract(size);
          // }
        }
      }
      if (!posible) break;
    }

    cout << (posible && tBarcos.empty() ? "SI" : "NO") << endl;
  }
  return 0;
}
