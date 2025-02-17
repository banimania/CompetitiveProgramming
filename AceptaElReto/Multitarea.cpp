#include <bits/stdc++.h>
using namespace std;

struct Tarea {
  int fechaInicio, fechaFin, periodo;
  bool operator<(const Tarea &otro) const {
    return fechaInicio > otro.fechaInicio;
  }
};

bool solve(int n, int m, int t) {
  priority_queue<Tarea> pq;

  for (int i = 0; i < n; i++) {
    int c, f;
    cin >> c >> f;
    pq.push({c, f, 0});
  }

  for (int i = 0; i < m; i++) {
    int c, f, periodo;
    cin >> c >> f >> periodo;
    pq.push({c, f, periodo});
  }

  int lastEnd = -1;

  while (!pq.empty()) {
    Tarea actual = pq.top();
    pq.pop();

    if (lastEnd > actual.fechaInicio) {
      return true;
    }

    lastEnd = actual.fechaFin;

    if (actual.periodo > 0) {
      int nextStart = actual.fechaInicio + actual.periodo;
      int nextEnd = actual.fechaFin + actual.periodo;

      if (nextStart < t) {
        pq.push({nextStart, nextEnd, actual.periodo});
      }
    }
  }

  return false;
}

int main() {
  int n, m, t;
  while (cin >> n >> m >> t) {
    cout << (solve(n, m, t) ? "SI" : "NO") << endl;
  }
  return 0;
}
