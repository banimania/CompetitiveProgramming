#include <bits/stdc++.h>

using namespace std;

struct Cinta {
  int duracion;
  int puntuacion;
};

int maxPuntuacion(int i, int j, int k, vector<Cinta> &cintas, vector<vector<vector<int>>> &dp) {
  if (j < 0 || k < 0) return INT_MIN;
  if (i == 0) return 0;
  if (dp[i][j][k] != -1) return dp[i][j][k];

  return dp[i][j][k] = max({
     maxPuntuacion(i - 1, j, k, cintas, dp),
     maxPuntuacion(i - 1, j - cintas[i - 1].duracion, k, cintas, dp) + cintas[i - 1].puntuacion,
     maxPuntuacion(i - 1, j, k - cintas[i - 1].duracion, cintas, dp) + cintas[i - 1].puntuacion
  });
}

int main() {
  int n;
  while (cin >> n && n) {
    int longCinta;
    cin >> longCinta;

    vector<Cinta> cintas(n);
    for (int i = 0; i < n; i++) {
      cin >> cintas[i].duracion >> cintas[i].puntuacion;
    }

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(longCinta + 1, vector<int>(longCinta + 1, -1)));

    cout << maxPuntuacion(n, longCinta, longCinta, cintas, dp) << endl;
  }
}
