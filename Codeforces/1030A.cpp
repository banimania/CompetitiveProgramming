#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  bool hard = false;
  for (int i = 0; i < n; i++) {
    int n;
    cin >> n;

    if (n) hard = true;
  }

  cout << (hard ? "HARD" : "EASY") << endl;
  return 0;
}
