#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  cout << 30 + ((n + (n > 7)) % 2) - (n == 2 ? 2 : 0) << endl;

  return 0;
}
