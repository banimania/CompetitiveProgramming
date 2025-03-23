#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> validBoard = {1, 1, 2, 2, 2, 8};

  for (int i = 0; i < 6; i++) {
    int x;
    cin >> x;
    cout << validBoard[i] - x << " ";
  }
  cout << endl;
  return 0;
}
