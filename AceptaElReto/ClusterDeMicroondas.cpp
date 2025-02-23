#include <bits/stdc++.h>
using namespace std;

bool tiempoEsperaPosible(int tiempoEspera, int numMicroondas, vector<pair<int, int>> &usuarios) {
  int tiempo = 0;

  priority_queue<int, vector<int>, function<bool(int, int)>> tiempoMicro([](const int &a, const int &b) {
    return a > b;
  });
  for (int i = 0; i < numMicroondas; i++) {
    tiempoMicro.push(0);
  }
  queue<pair<int, int>> q;
  for (int i = 0; i < usuarios.size(); i++) {
    q.push(usuarios[i]);
  }

  while (!q.empty()) {
    pair<int, int> usuario = q.front();
    q.pop();

    int minTiempo = tiempoMicro.top();
    tiempoMicro.pop();

    int tiempoInicio = max(minTiempo, usuario.first);
    int tiempoEsperado = tiempoInicio - usuario.first;
    tiempoMicro.push(tiempoInicio + usuario.second);

    if (tiempoEsperado > tiempoEspera) return false;
  }

  return true;
}

int main() {
  int n, t;
  while (cin >> n >> t) {
    if (!n && !t) return 0;

    vector<pair<int, int>> usuarios(n);
    for (int i = 0; i < n; i++) {
      cin >> usuarios[i].first >> usuarios[i].second;
    }

    int alto = 50005;
    int bajo = 1;

    int ans = INT_MAX;
    while (alto >= bajo) {
      int medio = (alto - bajo) / 2 + bajo;
      if (tiempoEsperaPosible(t, medio, usuarios)) {
        ans = min(ans, medio);
        alto = medio - 1;
      } else {
        bajo = medio + 1;
      }
    }

    cout << ans << endl;
  }
  return 0;
}
