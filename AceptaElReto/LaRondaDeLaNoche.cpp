#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Sensor {
  int i, j, n;
};

void solve() {
  int ancho, alto;
  cin >> ancho >> alto;

  pair<int, int> entrada = {-1, -1}, salida = {-1, -1};
  vector<vector<int>> mapa(alto, vector<int>(ancho, 0)); // 0 = libre, 1 = muro, 2 = sensor
  vector<Sensor> sensores;

  for (int i = 0; i < alto; i++) {
    for (int j = 0; j < ancho; j++) {
      char x;
      cin >> x;

      if (x == '#') mapa[i][j] = 1;
      else if (x == 'E') entrada = {i, j};
      else if (x == 'P') salida = {i, j};
      else if (isdigit(x)) {
        int n = x - '0';
        mapa[i][j] = 2;

        sensores.push_back({i, j, n});
      }
    }
  }

  for (int x = 0; x < sensores.size(); x++) {
    int i = sensores[x].i;
    int j = sensores[x].j;
    int n = sensores[x].n;

    // arriba
    for (int a = i - 1; a >= max(0, i - n); a--) {
      if (mapa[a][j] == 1) break;
      mapa[a][j] = 2;
    }
    // abajo
    for (int a = i + 1; a <= min(alto - 1, i + n); a++) {
      if (mapa[a][j] == 1) break;
      mapa[a][j] = 2;
    }
    // izquierda
    for (int a = j - 1; a >= max(0, j - n); a--) {
      if (mapa[i][a] == 1) break;
      mapa[i][a] = 2;
    }
    // derecha
    for (int a = j + 1; a <= min(ancho - 1, j + n); a++) {
      if (mapa[i][a] == 1) break;
      mapa[i][a] = 2;
    }
  }

  vector<vector<int>> minDist(alto, vector<int>(ancho, INT_MAX));
  queue<pair<int, int>> q;
  if (mapa[entrada.first][entrada.second] || mapa[salida.first][salida.second]) {
    cout << "NO" << endl;
    return;
  }

  q.push(entrada);
  minDist[entrada.first][entrada.second] = 0;
  while (!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();

    for (int dir = 0; dir < dirs.size(); dir++) {
      int dirI = dirs[dir].first;
      int dirJ = dirs[dir].second;

      int newI = i + dirI;
      int newJ = j + dirJ;

      int newDist = minDist[i][j] + 1;

      if (newI >= 0 && newI < alto && newJ >= 0 && newJ < ancho && !mapa[newI][newJ] && minDist[newI][newJ] > newDist) {
        minDist[newI][newJ] = newDist;
        q.push({newI, newJ});
      }
    }
  }

  cout << (minDist[salida.first][salida.second] == INT_MAX ? "NO" : to_string(minDist[salida.first][salida.second])) << endl;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
