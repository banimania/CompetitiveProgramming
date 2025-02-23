#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> freq;
  int x;
  while (cin >> x) {
    if (!x) {
      if (freq.empty()) return 0;
      vector<int> sol;
      bool posible = true;
      int maximo = INT_MIN;
      for (pair<int, int> pares : freq) {
        int diametro = pares.first;
        int num = pares.second;

        maximo = max(maximo, diametro);
      }

      for (pair<int, int> pares : freq) {
        int diametro = pares.first;
        int num = pares.second;

        if (diametro != maximo) {
          if (num != 2) {
            posible = false;
            break;
          }
          sol.push_back(diametro);
        } else {
          if (num != 1) {
            posible = false;
            break;
          }
        }
      }

      if (posible) {
        if (sol.empty()) {
          cout << maximo << endl;
        } else {
          for (int i = 0; i < sol.size(); i++) {
            cout << sol[i] << " ";
          }
          cout << maximo << " ";
          for (int i = sol.size() - 1; i >= 0; i--) {
            cout << sol[i] << (i == 0 ? "" : " ");
          }
          cout << endl;
        }

      } else {
        cout << "NO" << endl;
      }

      freq.clear();
      continue;
    }

    freq[x]++;
  }

  return 0;
}
