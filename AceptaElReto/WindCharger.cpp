// TODO: arreglar wrong answer sin sentido

#include <bits/stdc++.h>
using namespace std;

struct Edge {
  pair<int, int> u, v;
  int cost;
};

vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main() {
  int w, h;
  while (cin >> w >> h) {
    vector<vector<char>> mapa(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> mapa[i][j];
      }
    }

    vector<Edge> edges;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mapa[i][j] == 'O') {
          int x, y, energyCost;
          cin >> x >> y >> energyCost;
          x--, y--;

          edges.push_back({{i, j}, {y, x}, energyCost});
        }
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (mapa[i][j] == 'O' || mapa[i][j] == '#') continue;
        for (int dir = 0; dir < dirs.size(); dir++) {
          int dirI = dirs[dir].first;
          int dirJ = dirs[dir].second;

          int newI = i + dirI;
          int newJ = j + dirJ;

          if (newI >= 0 && newI < h && newJ >= 0 && newJ < w) {
            if (mapa[newI][newJ] == '#') continue;
            else {
              edges.push_back({{i, j}, {newI, newJ}, 1});
            }
          }
        }
      }
    }

    pair<int, int> inicio = {0, 0}, fin = {h - 1, w - 1};

    vector<vector<int>> dist(h, vector<int>(w, INT_MAX));
    dist[inicio.first][inicio.second] = 0;

    for (int i = 0; i < w * h - 1; i++) {
      for (const Edge &edge : edges) {
        if (dist[edge.u.first][edge.u.second] != INT_MAX && dist[edge.v.first][edge.v.second] > dist[edge.u.first][edge.u.second] + edge.cost) {
          dist[edge.v.first][edge.v.second] = dist[edge.u.first][edge.u.second] + edge.cost;
        }
      }
    }

    bool negativeCycles = false;
    for (const Edge &edge : edges) {
      if (dist[edge.u.first][edge.u.second] != INT_MAX && dist[edge.v.first][edge.v.second] > dist[edge.u.first][edge.u.second] + edge.cost) {
        negativeCycles = true;
        break;
      }
    }

    if (negativeCycles) {
      cout << "EXPLOSION" << endl;
      continue;
    }

    if (dist[fin.first][fin.second] == INT_MAX) {
      cout << "IMPOSIBLE" << endl;
      continue;
    }

    cout << dist[fin.first][fin.second] << endl;
  }
  return 0;
}
