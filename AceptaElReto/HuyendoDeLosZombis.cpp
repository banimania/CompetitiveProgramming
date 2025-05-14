#include <bits/stdc++.h>
using namespace std;

struct State {
  int nodo, tiempoActual, tiempoEsperado;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    int m;
    cin >> m;

    vector<vector<int>> linea(m);
    vector<vector<pair<int, int>>> times(n, vector<pair<int, int>>(m, {-1, -1}));
    unordered_map<int, set<int>> lineaNodo;
    cin.ignore();
    for (int i = 0; i < m; i++) {
      int currentTime = 0;
      string line;
      getline(cin, line);

      istringstream iss(line);
      int cnt = 0, x = 0;
      while (iss >> x) {
        if (cnt % 2) {
          currentTime += x;
        } else {
          x--;
          times[x][i] = {currentTime, cnt / 2};
          linea[i].push_back(x);

          lineaNodo[x].insert(i);
        }
        cnt++;
      }
    }

    priority_queue<State, vector<State>, function<bool(State, State)>> pq([](const State &a, const State &b) {
      return a.tiempoEsperado > b.tiempoEsperado;
    });
    pq.push({0, 0, 0});

    vector<pair<int, int>> minT(n, {INT_MAX, INT_MAX}); // guarda el min {minTEsperado, minTActual}
    minT[0] = {0, 0};
    while (!pq.empty()) {
      State curr = pq.top();
      // cout << curr.nodo << " " << curr.tiempoActual << " " << curr.tiempoEsperado << endl;
      pq.pop();

      if (curr.tiempoEsperado > minT[curr.nodo].first || curr.tiempoActual > minT[curr.nodo].second) continue;

      if (curr.nodo == n - 1) {
        break;
      }

      for (int i : lineaNodo[curr.nodo]) {
        if (times[curr.nodo][i].first != -1) {
          int nextStop = linea[i][(times[curr.nodo][i].second + 1) % linea[i].size()];

          int tiempoEsperado;
          if (curr.tiempoActual <= times[curr.nodo][i].first) {
            tiempoEsperado = times[curr.nodo][i].first - curr.tiempoActual;
          } else {
            tiempoEsperado = 60 - curr.tiempoActual + times[curr.nodo][i].first;
          }

          int newTiempoTotalEsperado = tiempoEsperado + curr.tiempoEsperado;

          int tiempoLlegada = times[nextStop][i].first;
          int tiempoTarda;
          if (curr.tiempoActual <= tiempoLlegada) {
            tiempoTarda = tiempoLlegada - curr.tiempoActual;
          } else {
            tiempoTarda = 60 - curr.tiempoActual + tiempoLlegada;
          }

          if (newTiempoTotalEsperado < minT[nextStop].first) {
            minT[nextStop] = {newTiempoTotalEsperado, curr.tiempoActual + tiempoTarda};
            pq.push({nextStop, curr.tiempoActual + tiempoTarda, newTiempoTotalEsperado});
          } else if (newTiempoTotalEsperado == minT[nextStop].first) {
            if (curr.tiempoActual + tiempoTarda < minT[nextStop].second) {
              minT[nextStop] = {newTiempoTotalEsperado, curr.tiempoActual + tiempoTarda};
              pq.push({nextStop, curr.tiempoActual + tiempoTarda, newTiempoTotalEsperado});
            }
          }
        }
      }

    }

    cout << ((minT[n - 1].first == INT_MAX) ? "Hoy no vuelvo" : to_string(minT[n - 1].first)) << endl;
  }
  return 0;
}
