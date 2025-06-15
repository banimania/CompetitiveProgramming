#include <bits/stdc++.h>
using namespace std;

bool cubifinito(int n, vector<int> &path, set<int> &seen) {
  path.push_back(n);

  if (n == 1) return true;
  if (seen.count(n)) {
    return false;
  }

  seen.insert(n);

  int suma = 0;

  int aux = n;
  while (aux) {
    int dig = aux % 10;
    suma += dig * dig * dig;
    aux /= 10;
  }

  if (n == 1) {
    path.push_back(1);
    return true;
  }

  return cubifinito(suma, path, seen);
}

int main() {
  int n;
  while (cin >> n && n) {
    set<int> seen;
    vector<int> path;
    bool ans = cubifinito(n, path, seen);

    for (int i = 0; i < path.size(); i++) {
      cout << path[i] << (i != path.size() - 1 ? " - " : "");
    }

    cout << " -> " << (ans ? "cubifinito" : "no cubifinito") << "." << endl;
  }
  return 0;
}
