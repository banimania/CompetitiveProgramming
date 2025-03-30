#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> problemNames(n);
  for (int i = 0; i < n; i++) {
    cin >> problemNames[i];
  }

  vector<int> totalScore(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      totalScore[j] += x;
    }
  }

  int winner = 0;
  
  for (int i = 1; i < n; i++) {
    if (totalScore[i] > totalScore[winner]) {
      winner = i;
    }
  }

  cout << problemNames[winner] << endl;
  return 0;
}
