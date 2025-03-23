#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  int s = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    s += x;
  }

  cout << (x >= s ? "Jebb" : "Neibb") << endl;
  return 0;
}
