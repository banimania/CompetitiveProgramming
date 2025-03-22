#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int best = INT_MIN;
  string bestName;

  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    int x;
    cin >> x;

    if (x > best) {
      bestName = name;
      best = x;
    }
  }
  cout << bestName << endl;
  return 0;
}
