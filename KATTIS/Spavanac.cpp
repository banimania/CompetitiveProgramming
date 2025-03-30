#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, m;
  cin >> h >> m;

  int totalMin = h * 60 + m;

  totalMin = (1440 + ((totalMin - 45) % 1440)) % 1440;

  h = totalMin / 60;
  m = totalMin % 60;

  cout << h << " " << m << endl;
  return 0;
}
