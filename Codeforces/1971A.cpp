#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  while(n--) {
    int x, y;
    cin >> x >> y;
    cout << min(x, y) << " " << max(x, y) << endl;
  }
  return 0; // desde el móvil para no perder la racha xd
}
