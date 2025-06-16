#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template<typename T>
void make_set(vector<T> &dsu, vector<T> &size, T v) {
  dsu[v] = v;
  size[v] = 1;
}

template<typename T>
int find_set(vector<T> &dsu, T v) {
  if (v == dsu[v]) return v;
  return dsu[v] = find_set(dsu, dsu[v]);
}

template<typename T>
void union_sets(vector<T> &dsu, vector<T> &size, T a, T b) {
  a = find_set(dsu, a);
  b = find_set(dsu, b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    dsu[b] = a;
    size[a] += size[b];
  }
}

int main() {
  int f, c;
  while (cin >> f >> c) {
    cin.ignore();
    vector<int> dsu(f * c), size(f * c);
    for (int i = 0; i < f * c; i++) {
      make_set(dsu, size, i);
    }
    vector<vector<char>> grid(f, vector<char>(c));

    for (int i = 0; i < f; i++) {
      string line;
      getline(cin, line);
      for (int j = 0; j < c; j++) {
        grid[i][j] = line[j];
      }
    }

    int ans = 0;
    for (int i = 0; i < f; i++) {
      for (int j = 0; j < c; j++) {
        if (grid[i][j] == '#') {
          for (int dir = 0; dir < dirs.size(); dir++) {
            int newI = i + dirs[dir].first;
            int newJ = j + dirs[dir].second;

            if (newI >= 0 && newI < f && newJ >= 0 && newJ < c && grid[newI][newJ] == '#') {
              union_sets(dsu, size, i * c + j, newI * c + newJ);
            } 
          }
          ans = max(ans, size[find_set(dsu, i * c + j)]);
        }
      }
    }

    cout << ans;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
      int currI, currJ;
      cin >> currI >> currJ;
      currI--, currJ--;
      grid[currI][currJ] = '#';

      for (int dir = 0; dir < dirs.size(); dir++) {
        int newI = currI + dirs[dir].first;
        int newJ = currJ + dirs[dir].second;

        if (newI >= 0 && newI < f && newJ >= 0 && newJ < c && grid[newI][newJ] == '#') {
          union_sets(dsu, size, currI * c + currJ, newI * c + newJ);
        } 
      }
      ans = max(ans, size[find_set(dsu, currI * c + currJ)]);
      cout << " " << ans;
    }

    cout << endl;
  }
  return 0;
}
