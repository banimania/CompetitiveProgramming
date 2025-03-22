#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  if (a == b) {
    cout << "WORLD WAR 3!" << endl;
  } else if (a > b) {
    cout << "MAGA!" << endl;
  } else {
    cout << "FAKE NEWS!" << endl;
  }

  return 0;
}
