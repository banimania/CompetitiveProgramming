#include <bits/stdc++.h>
using namespace std;

int main() {
  int last = -1, x;
  while (cin >> x) {
    if (last == -1) {
      last = x;
      continue;
    }

    if (last + 1 != x) {
      cout << last << endl;
    }

    last = x;
  }
  cout << last << endl;
}
