#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  int x, ninos = 0;
  int currSuma = 0;
  while (cin >> x) {
    if (!x) {
      if (!currSuma) break;
      else {
        cout << (currSuma % ninos == 0 ? "REPARTO JUSTO\n" : "IMPOSIBLE\n");
        ninos = 0;
        currSuma = 0;
        continue;
      }
    }
    
    currSuma += x;
    ninos++;
    
  }
  return 0;
}
