#include <bits/stdc++.h>
using namespace std;

bool posible(int p, int maxCompartidos, vector<int> &instr) {
  int partNecesarias = 0;
  for (int i = 0; i < instr.size(); i++) {
    partNecesarias += (int) ceil(instr[i] / (double) maxCompartidos);
  }

  return partNecesarias <= p;
}
int main() {
  int p, n;
  while (cin >> p >> n) {
    vector<int> instr(n);
    int maxInstr = INT_MIN;
    for (int i = 0; i < n; i++) {
      cin >> instr[i];
      maxInstr = max(instr[i], maxInstr);
    }

    int alto = maxInstr;
    int bajo = 1;

    while (alto >= bajo) {
      int medio = (alto - bajo) / 2 + bajo;

      if (posible(p, medio, instr)) {
        alto = medio - 1;
      } else {
        bajo = medio + 1;
      }
    }

    cout << (alto - bajo) / 2 + bajo << endl;
  }
  return 0;
}
