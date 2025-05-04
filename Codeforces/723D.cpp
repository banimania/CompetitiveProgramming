#include <bits/stdc++.h>
using namespace std;

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

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs0(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
  for (auto [dirI, dirJ] : dirs) {
    int newI = i + dirI;
    int newJ = j + dirJ;

    if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == '.' && !visited[newI][newJ]) {
      visited[newI][newJ] = true;
      dfs0(newI, newJ, grid, visited);
    }
  }
}

void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, vector<int> &dsu, vector<int> &size) {
  for (auto [dirI, dirJ] : dirs) {
    int newI = i + dirI;
    int newJ = j + dirJ;

    if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == '.' && !visited[newI][newJ]) {
      visited[newI][newJ] = true;
      union_sets(dsu, size, i * (int) grid[0].size() + j, newI * (int) grid[0].size() + newJ);
      dfs(newI, newJ, grid, visited, dsu, size);
    }
  }
}

void dfs2(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, vector<int> &dsu, vector<int> &size) {
  for (auto [dirI, dirJ] : dirs) {
    int newI = i + dirI;
    int newJ = j + dirJ;

    if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == '.' && !visited[newI][newJ]) {
      visited[newI][newJ] = true;
      grid[newI][newJ] = '*';
      dfs2(newI, newJ, grid, visited, dsu, size);
    }
  }

}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<char>> grid(n, vector<char>(m));
  vector<int> dsu(n * m), size(n * m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      make_set(dsu, size, i * m + j);
    }
  }

  vector<vector<bool>> visited(n, vector<bool>(m));

  for (int i = 0; i < n; i++) {
    if (grid[i][0] == '.' && !visited[i][0]) {
      visited[i][0] = true;
      dfs0(i, 0, grid, visited);
    }
    if (grid[i][m - 1] == '.' && !visited[i][m - 1]) {
      visited[i][m - 1] = true;
      dfs0(i, m - 1, grid, visited);
    }
  }
  for (int j = 0; j < m; j++) {
    if (grid[0][j] == '.' && !visited[0][j]) {
      visited[0][j] = true;
      dfs0(0, j, grid, visited);
    }
    if (grid[n - 1][j] == '.' && !visited[n - 1][j]) {
      visited[n - 1][j] = true;
      dfs0(n - 1, j, grid, visited);
    }
  }

  map<int, pair<int, int>> lakeCoords;
  set<int> lakes;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '.' && !visited[i][j]) {
        visited[i][j] = true;
        dfs(i, j, grid, visited, dsu, size);
        lakes.insert(find_set(dsu, i * m + j));
        lakeCoords[find_set(dsu, i * m + j)] = {i, j};
      }
    }
  }

  vector<pair<int, int>> lakesAndSizes;
  for (int lake : lakes) {
    lakesAndSizes.push_back({lake, size[lake]});
  }

  sort(lakesAndSizes.begin(), lakesAndSizes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
  });

  int needRemoval = lakes.size() - k;
  int ans = 0;

  visited = vector<vector<bool>>(n, vector<bool>(m));
  int i = 0;
  while (needRemoval > 0) {
    int lake = lakesAndSizes[i].first;
    pair<int, int> coords = lakeCoords[lake];
    ans += lakesAndSizes[i].second;
    i++;
    needRemoval--;
    grid[coords.first][coords.second] = '*';
    dfs2(coords.first, coords.second, grid, visited, dsu, size);
  }

  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << grid[i][j];
    }
    cout << endl;
  }

  return 0;
}
