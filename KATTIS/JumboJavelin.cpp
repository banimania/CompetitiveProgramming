#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int total = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    total += x;
  }

  total -= (n - 1);
  cout << total << endl;
  return 0;
}
