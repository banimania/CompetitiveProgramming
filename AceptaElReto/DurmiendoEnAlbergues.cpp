#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  
  while (cin >> s) {
    int primeraX = -1, ultimaX = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'X') {
        primeraX = i;
        break;
      }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == 'X') {
        ultimaX = i;
        break;
      }
    }

    vector<int> dist(s.size());
    int vacios = primeraX;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'X') {
        vacios = 0;
      } else {
        vacios++;
      }

      dist[i] = vacios;
    }
    int ans = INT_MIN;
    vacios = (s.size() - ultimaX);
    for (int i  = s.size() - 1; i >= 0; i--) {
      if (s[i] == 'X') {
        vacios = 0;
      } else {
        vacios++;
      }

      dist[i] = min(dist[i], vacios);
      ans = max(ans, dist[i]);
    }

    cout << ans - 1 << endl;
    
  }

  return 0;
}
