#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  vector<bool> manager(n, true);;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == -1) continue;

    manager[i] = false;

    x--;

    adj[x].push_back(i);
  }

  int maxAltura = 0;

  vector<bool> visitado(n, false);
  for (int i = 0; i < n; i++) {
    if (!visitado[i] && manager[i]) {
      queue<pair<int, int>> q;
      visitado[i] = true;
      q.push({i, 1});
      while (!q.empty()) {
        int nodo = q.front().first;
        int altura = q.front().second;
        q.pop();

        maxAltura = max(altura, maxAltura);

        for (int vecino : adj[nodo]) {
          if (!visitado[vecino]) {
            visitado[vecino] = true;
            q.push({vecino, altura + 1});
          }
        }
      }
    }
  }

  cout << maxAltura << endl;
  
  return 0;
}
